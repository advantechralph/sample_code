#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
${scriptdir}/overlay.sh
${scriptdir}/mount.sh
set +x
