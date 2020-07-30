#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
umount ${overlaydir}/merged/dev/pts
umount ${overlaydir}/merged/dev
umount ${overlaydir}/merged/proc
umount ${overlaydir}/merged/sys
umount ${overlaydir}/merged/media/sf_share
set +x
