#!/bin/bash
prog=test
usage(){
cat << EOF
Usage: 

  $prog [OPTION]... [PARAMETER]

OPTION: 
  -a, --append                append command
  -c                          c command
  -h                          show this usage

PARAMETER: 
  -a, --append                append parameter

EOF
}
if [ "$#" -eq 0 ] ; then
  usage
  exit 0; 
fi
# getopt -n test -o a:ch --long test:  --long xxx: -- -a 111 -b 222 -c -h --test 333 --xxx 555
options=$(getopt -n $prog -o a:ch -l append: -l help  -- "$@")
if [ "$?" -ne 0 ] ; then
  usage
  exit 0; 
fi
c=0
h=0
eval set -- "$options"
while true ; do
  case "$1" in
    -a|--append)
      shift
      a=$1
      ;;
    -c)
      c=1
      ;;
    -h|--help)
      h=1
      ;;
    --)
      break; 
      ;;
  esac
  shift
done

if [ "$h" -eq 1 ]; then
  usage
fi

cat << EOF
a=$a
c=$c
h=$h
EOF

