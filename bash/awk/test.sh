#!/bin/bash

# RS is for big range, FS is for field, NR is line number
echo -ne "1:2:3\t2:3:4\t" | awk 'BEGIN{RS="\t";FS=":"} {print "line "NR": $1="$1}'
# ORS is for output
echo -ne "1:2:3\t2:3:4\t" | awk 'BEGIN{RS="\t";FS=":"} {ORS="(append ORS)\n"; print "line "NR": $1="$1}'
# condition
cat << EOF | awk 'BEGIN {FS=":";a=""} NR%3==1 && a!="" {a=a","$1} NR%3==1 && a=="" {a=$1} END {print a}'
1:2:3
4:5:6
7:8:9
a:b:c
d:e:f
g:h:i
EOF
# regex condition
cat << EOF | awk '$2 ~ /ooxx/ {print "line "NR": $2 includes ooxx!!"}'
fdhfbvvf uytumyooxxtkn4r  nbfhbsf
snfjooxxsjnfs mskfks
fskmfk fksmk ksmfkms
EOF


