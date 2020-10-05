###############################################
#                    Path                     #
###############################################
currdir=$(shell pwd)
builddir=${currdir}/build
packagedir=$(builddir)/$(name)
debiandir=$(packagedir)/DEBIAN
debfile=$(builddir)/$(name).deb
###############################################
#                  Package                    #
###############################################
name=kernel-update
version=0.1
revision=1
#arch=armhf
arch=arm64
define desc
Advantech MIC-710GS kernel update testing                                        
endef
define editor
Ralph Wang <advantechralph@gmail.com>
endef
define depends
sed (>=4.4)
endef
###############################################
#                 Environment                 #
###############################################
SHELL=/bin/bash
export SHELL desc editor depends
