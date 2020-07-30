#!/bin/bash
in=${1:-inputFile}
out=${2:-outputFile}

awk '
BEGIN {FS="    ";ORS="";} 
{ 
  for(i=1;i<=NF;i++){
    if(i==NF){ 
      print $i"\n" 
    }else{ 
      print $i"\t"; 
    } 
  }
}' $in > $out
