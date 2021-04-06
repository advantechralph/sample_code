#!/bin/bash
(echo -ne "float sineTable[]={\n" ; for i in $(seq 0 1 360) ; do  echo "scale=10;pi=4*a(1);s((pi/180)*$i)"| bc -l | awk '{printf "  %f", $0; if('$i'!=360) printf "," ; printf "\n"}'; done ; echo -ne "};") > sineTable.c
