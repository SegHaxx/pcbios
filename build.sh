#!/bin/sh
dosbox -c 'config -set "dos ems=off"' -c 'config -set "cpu cycles=max"' \
-noautoexec -exit BUILDV3.BAT
echo "sha256 checksum for original unmodified V3 BIOS is:"
echo "3700c345f3dcb76039986429ade9ff0cffbc2f0cae535b987b95a5de8aa0094f"
sha256sum PCBIOSV3.IMG
