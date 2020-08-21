builddir=$(PWD)/build
srcsdir=$(PWD)/srcs
incdir=$(PWD)/inc
c_srcs=$(wildcard srcs/*.c)
cpp_srcs=$(wildcard srcs/*.cpp)

maketargets=$(foreach f,$(1),$(shell b=$$(basename $(f)); s=$${b\#\#*.}; n=$${b%%.*} ; echo $${n}_$${s}; ) )
c_targets=$(call maketargets,$(c_srcs))
cpp_targets=$(call maketargets,$(cpp_srcs))

cflags=-Wall --save-temp -I$(incdir)
cxxflags=$(cflags) --std=c++11


