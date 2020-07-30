#!/bin/bash
#[ -n $1 ] && (dpkg -l $1 > /dev/null 2>&1 && echo $?)
[ -n $1 ] && ( \
  if [ -n "$(dpkg -l $1 > /dev/null 2>&1 && echo $?)" ] ; then \
    echo "$1: installed!!"; \
  else \
    echo "$1: not installed!!"; \
  fi \
)

