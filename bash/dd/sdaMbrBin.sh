#!/bin/bash
# MBR Total Size
#     446 + 64 + 2 = 512
# Where,
#     446 bytes – Bootstrap.
#     64 bytes – Partition table.
#     2 bytes – Signature.
# extract mbr
dd if=/dev/sda of=mbr.bin bs=512 count=1
#dd if=/tmp/mbrsda.bak of=/dev/sdb bs=446 count=1
