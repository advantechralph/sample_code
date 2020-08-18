#!/bin/bash
currdir=$(dirname $(realpath ${BASH_SOURCE[0]}))
builddir=${currdir}/build
nameserver=8.8.8.8
hostname=test
mkdir -p ${builddir}
ret=$(mountpoint -q build; echo $?)
[ ! ${ret:-1} -eq 0 ] && (mount -t tmpfs tmpfs ${builddir}) 
mkdir -p ${builddir}/{merged,upper,work}
cat << EOF > ${builddir}/resolv.conf
nameserver ${nameserver}
EOF
cat << EOF > ${builddir}/hostname
${hostname}
EOF
modprobe overlay
mount -t overlay overlay -o lowerdir=/,upperdir=${builddir}/upper,workdir=${builddir}/work ${builddir}/merged
mount -o bind /dev ${builddir}/merged/dev 
mount -o bind /dev/pts ${builddir}/merged/dev/pts
mount -t proc proc ${builddir}/merged/proc
mount -t sysfs sys ${builddir}/merged/sys
mount -o bind ${builddir}/resolv.conf ${builddir}/merged/etc/resolv.conf
mount -o bind ${builddir}/hostname ${builddir}/merged/etc/hostname
