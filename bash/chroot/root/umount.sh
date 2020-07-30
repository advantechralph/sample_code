#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
umount ${overlaydir}/merged/run
umount ${overlaydir}/merged/dev/shm
umount ${overlaydir}/merged/dev/pts
umount ${overlaydir}/merged/dev
[ -d '/work' ] && umount ${overlaydir}/merged/work
umount ${overlaydir}/merged/proc
umount ${overlaydir}/merged/sys
umount ${overlaydir}/merged/media/sf_share
set +x
