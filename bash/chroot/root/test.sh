#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
printf "%-20s: %s\n" "lowerdir" $lowerdir
printf "%-20s: %s\n" "overlaydir" $overlaydir
set +x
