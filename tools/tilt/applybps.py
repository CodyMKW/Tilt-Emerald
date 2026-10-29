#!/usr/bin/env python3
import sys, zlib
def rv(p, i):
    n = 0; shift = 1
    while True:
        x = p[i]; i += 1
        n += (x & 0x7f) * shift
        if x & 0x80: return n, i
        shift <<= 7; n += shift
src = open(sys.argv[1], 'rb').read(); p = open(sys.argv[2], 'rb').read()
assert p[:4] == b'BPS1'
i = 4
S, i = rv(p, i); T, i = rv(p, i); M, i = rv(p, i); i += M
out = bytearray(); rel = 0; end = len(p) - 12
while i < end:
    v, i = rv(p, i); mode = v & 3; l = (v >> 2) + 1
    if mode == 0: out += src[len(out):len(out) + l]
    elif mode == 1: out += p[i:i + l]; i += l
    elif mode == 2:
        d, i = rv(p, i); rel += -(d >> 1) if d & 1 else (d >> 1)
        out += src[rel:rel + l]; rel += l
    else: raise SystemExit('targetcopy unsupported')
assert len(out) == T, (len(out), T)
open(sys.argv[3], 'wb').write(out)
print('crc', hex(zlib.crc32(out)))
