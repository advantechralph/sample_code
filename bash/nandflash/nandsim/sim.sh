#!/bin/bash

# if you want to output to file...
# cache_file=
modprobe nandsim first_id_byte=0xec \
 second_id_byte=0xd3 \
 third_id_byte=0x51 \
 fourth_id_byte=0x95 \
 parts=0x1000,0x800

# cat /proc/mtd
# dev:    size   erasesize  name
# mtd0: 20000000 00020000 "NAND simulator partition 0"
# mtd1: 10000000 00020000 "NAND simulator partition 1"
# mtd2: 10000000 00020000 "NAND simulator partition 2"

