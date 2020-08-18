#!/bin/bash
currdir=$(dirname $(realpath ${BASH_SOURCE[0]}))
builddir=${currdir}/build
umount ${builddir}/merged/etc/hostname
umount ${builddir}/merged/etc/resolv.conf
umount ${builddir}/merged/sys
umount ${builddir}/merged/proc
umount ${builddir}/merged/dev/pts
umount ${builddir}/merged/dev
umount ${builddir}/merged
umount ${builddir}
