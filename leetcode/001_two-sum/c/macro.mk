builddir=$(currdir)/build
srcsdir=$(currdir)/srcs
incdir=$(currdir)/inc
target=$(builddir)/hello
srcs=$(wildcard $(srcsdir)/*.c)
S:=1
quiet:=$(shell [ $(S) -eq 1 ] && echo ">/dev/null 2>&1" )
SHELL:=/bin/bash
CC:=$(CROSS_COMPILE)gcc
CFLAGS=-I$(incdir) -Wall
