builddir=$(currdir)/build
srcsdir=$(currdir)/srcs
incdir=$(currdir)/inc
target=$(builddir)/sample
srcs=$(wildcard $(srcsdir)/*.cpp)
S:=1
quiet:=$(shell [ $(S) -eq 1 ] && echo ">/dev/null 2>&1" )
SHELL:=/bin/bash
CC:=$(CROSS_COMPILE)gcc
CXX:=$(CROSS_COMPILE)g++
CFLAGS=-I$(incdir) -Wall
# CXXFLAGS=$(CFLAGS) -std=c++11 
CXXFLAGS=$(CFLAGS) -std=c++98
