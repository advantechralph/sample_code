#!/bin/bash
#set -x
scriptpath=${BASH_SOURCE[0]}
scriptdir=$(realpath $(dirname ${scriptpath}))
source ${scriptdir}/config
mount -o bind /dev ${overlaydir}/merged/dev
mount -t proc proc ${overlaydir}/merged/proc
mount -t sysfs sys ${overlaydir}/merged/sys
mount -o bind /media/sf_share ${overlaydir}/merged/media/sf_share
mount -o bind /dev/pts ${overlaydir}/merged/dev/pts
sed -i -e '$a#chroot PS1\nPS1='"'"'${debian_chroot:+($debian_chroot)}\\u@'"$(basename ${overlaydir})"':\\w\\\$ '"'" -e '/#chroot PS1/,+2d' ${overlaydir}/merged/root/.bashrc
set +x
