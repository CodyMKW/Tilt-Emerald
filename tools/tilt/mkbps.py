#!/usr/bin/env python3
"""mkbps.py SOURCE TARGET OUT.bps  -- simple BPS patch creator (SourceRead / TargetRead / SourceCopy)."""
import sys, zlib, numpy as np

def varint(n):
    out = bytearray()
    while True:
        x = n & 0x7f
        n >>= 7
        if n:
            out.append(x)
            n -= 1
        else:
            out.append(0x80 | x)
            return bytes(out)

src = open(sys.argv[1], 'rb').read()
tgt = open(sys.argv[2], 'rb').read()
S, T = len(src), len(tgt)
sa = np.frombuffer(src, dtype=np.uint8)
ta = np.frombuffer(tgt, dtype=np.uint8)
W = 8

def windows(a):
    n = len(a) - W + 1
    v = np.zeros(n, dtype=np.uint64)
    for i in range(W):
        v |= a[i:i + n].astype(np.uint64) << np.uint64(8 * i)
    return v

sw = windows(sa)
tw = windows(ta)
# index source windows at every 2nd offset (skip all-same/blank windows to avoid junk matches)
idx = np.arange(0, len(sw), 2)
keys = sw[idx]
order = np.argsort(keys, kind='stable')
keys_sorted = keys[order]
pos_sorted = idx[order]
ins = np.searchsorted(keys_sorted, tw)
ins[ins >= len(keys_sorted)] = len(keys_sorted) - 1
hit = keys_sorted[ins] == tw
cand = np.where(hit, pos_sorted[ins], -1)

def match_len(s, t):
    n = min(S - s, T - t)
    step = 4096
    l = 0
    while l < n:
        m = min(step, n - l)
        a = sa[s + l:s + l + m]
        b = ta[t + l:t + l + m]
        ne = np.nonzero(a != b)[0]
        if len(ne):
            return l + int(ne[0])
        l += m
    return l

out = bytearray(b'BPS1')
out += varint(S) + varint(T) + varint(0)
t = 0
pending = bytearray()
rel = 0
MIN = 12

def flush():
    global pending
    if pending:
        out.extend(varint(((len(pending) - 1) << 2) | 1))
        out.extend(pending)
        pending = bytearray()

while t < T:
    # same-offset run?
    l0 = match_len(t, t) if t < S else 0
    best_len, best_s = l0, t
    c = int(cand[t]) if t < len(cand) else -1
    if c >= 0 and c != t:
        l1 = match_len(c, t)
        if l1 > best_len:
            best_len, best_s = l1, c
    if best_len >= MIN or (best_s == t and best_len >= 4 and not pending):
        flush()
        if best_s == t and best_len >= 1 and (rel == t or True):
            if best_s == t:
                out.extend(varint(((best_len - 1) << 2) | 0))
                # SourceRead does not move sourceRelativeOffset
        if best_s != t:
            out.extend(varint(((best_len - 1) << 2) | 2))
            d = best_s - rel
            out.extend(varint((abs(d) << 1) | (1 if d < 0 else 0)))
            rel = best_s + best_len
        t += best_len
    else:
        pending.append(tgt[t])
        t += 1
flush()
out += (zlib.crc32(src) & 0xffffffff).to_bytes(4, 'little')
out += (zlib.crc32(tgt) & 0xffffffff).to_bytes(4, 'little')
out += (zlib.crc32(bytes(out)) & 0xffffffff).to_bytes(4, 'little')
open(sys.argv[3], 'wb').write(out)
print('patch bytes', len(out))
