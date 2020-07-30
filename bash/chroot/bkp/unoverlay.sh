#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
mkdir -p ${overlaydir}/{upper,merged,work}
umount ${overlaydir}/merged
set +x
