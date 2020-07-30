#!/bin/bash
in=${1:-inputFile}
out=${2:-outputFile}
# NR is line number, OFS is for output seperate
awk -F "\xa" 'NR%3==1 && NR!=1 {ORS="\xa"; print $0} NR%3==2 {ORS="\x09"; print $0} NR%3==0 {ORS="\x09" ; print $0} ' $in > $out
