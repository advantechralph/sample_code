#!/bin/bash

# Disk hdd.img: 10 MiB, 10485760 bytes, 20480 sectors
# Units: sectors of 1 * 512 = 512 bytes
# Sector size (logical/physical): 512 bytes / 512 bytes
# I/O size (minimum/optimal): 512 bytes / 512 bytes
# Disklabel type: dos
# Disk identifier: 0xfb8cdb0e
# 
# Device     Boot Start   End Sectors Size Id Type
# hdd.img1         2048 20479   18432   9M 83 Linux

dd if=/dev/zero of=hdd.img bs=1024 count=10240

sed -e 's/\s*\([\+0-9a-zA-Z]*\).*/\1/' << EOF | fdisk hdd.img
  o # clear the in memory partition table
  n # new partition
  p # primary partition
  1 # partition number 1
    # default - start at beginning of disk 
  +2M # 2 MB boot parttion
  n # new partition
  p # primary partition
  2 # partion number 2
    # default, start immediately after preceding partition
    # default, extend partition to end of disk
  a # make a partition bootable
  1 # bootable partition is partition 1 -- /dev/sda1
  p # print the in-memory partition table
  w # write the partition table
  q # and we're done
EOF

fdisk -l hdd.img

