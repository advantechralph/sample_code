#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
mkdir -p ${overlaydir}/{upper,merged,work}
modprobe overlay
mount -t overlay overlay -olowerdir=${lowerdir},upperdir=${overlaydir}/upper,workdir=${overlaydir}/work ${overlaydir}/merged
set +x
