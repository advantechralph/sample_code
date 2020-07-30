#!/bin/bash
packages="virtualbox"

for p in $packages; do
  if [ -n "$(dpkg -l $p > /dev/null 2>&1 && echo $?)" ] ; then 
     printf "%-20s installed!!\n" "$p:"; 
  else 
     printf "%-20s not installed!!\n" "$p:"; 
     apt-get install -y $p
  fi 
done
