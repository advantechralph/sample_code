#!/bin/bash
for i in $(seq 10 -1 3) ; do 
  printf "%${i}s%$[10-${i}]s" "xxx" ""; 
  sleep 1; 
  printf "\r";
done
