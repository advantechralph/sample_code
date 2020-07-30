#!/bin/bash
set -x
[ -n "$1" ] && echo "\$1: $1"
[ -z "$1" ] && echo "\$1: not exists!!"
