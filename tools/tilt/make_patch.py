#!/usr/bin/env python3
"""make_patch.py VANILLA_EMERALD.gba TILT.gba VERSION

Writes docs/patch/tilt-emerald.bps and docs/patch/info.json for the GitHub Pages builder.
VANILLA_EMERALD.gba must be Pokemon Emerald (U), SHA-1 f3ae088181bf583e55daf962a92bb46f4f1d07b7
(building the pret/pokeemerald base commit 731ad5b gives a byte-identical file).
Never commit a ROM; only the patch goes in the repo.
"""
import hashlib, json, os, subprocess, sys, zlib

van, tilt, version = sys.argv[1:4]
here = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(here, '..', '..'))
out = os.path.join(root, 'docs', 'patch')
os.makedirs(out, exist_ok=True)
v = open(van, 'rb').read()
t = open(tilt, 'rb').read()
assert hashlib.sha1(v).hexdigest() == 'f3ae088181bf583e55daf962a92bb46f4f1d07b7', 'not vanilla Emerald (U)'
subprocess.check_call([sys.executable, os.path.join(here, 'mkbps.py'), van, tilt, os.path.join(out, 'tilt-emerald.bps')])
info = {
    'version': version,
    'sourceSha1': 'f3ae088181bf583e55daf962a92bb46f4f1d07b7',
    'sourceCrc32': '%08x' % (zlib.crc32(v) & 0xffffffff),
    'sourceSize': len(v),
    'targetCrc32': '%08x' % (zlib.crc32(t) & 0xffffffff),
    'targetSize': len(t),
    'patchSize': os.path.getsize(os.path.join(out, 'tilt-emerald.bps')),
}
json.dump(info, open(os.path.join(out, 'info.json'), 'w'), indent=2)
print(info)
