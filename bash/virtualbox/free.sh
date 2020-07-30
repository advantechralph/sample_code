#!/bin/bash
dd if=/dev/zero of=./bigemptyfile bs=4096k; rm -rf ./bigemptyfile
# VBoxManage modifyhd --compact xxx.vdi
