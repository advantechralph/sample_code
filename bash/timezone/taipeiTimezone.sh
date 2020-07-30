#!/bin/bash
[ -z "$(dpkg -l tzdata > /dev/null 2>&1 && echo $?)" ] \
  && apt-get update && apt-get install -y tzdata
echo "Asia/Taipei" > /etc/timezone
ln -sf /usr/share/zoneinfo/Asia/Taipei /etc/localtime

