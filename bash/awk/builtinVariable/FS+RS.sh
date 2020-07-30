#!/bin/bash
set -x
awk '
BEGIN{
  FS="\n";
  RS="\n\n";
}
{
  print $1
}
' << EOF
111 222 333
444 555
666

a b c d
e f g h

oooo vvvv gggg
ssss tttt uuuu vvvv 
wwww xxxx yyyy zzzz
kkkk llll mmmm

EOF
