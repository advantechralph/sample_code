currdir=$(PWD)
topdir=$(realpath $(currdir)/..)
#str-splitter=$(word $3,$(subst $2, ,$1))
#BUILDROOTDIR=$(call str-splitter,$(topdir),test,1)
#TOOLCHAINDIR=$(BUILDROOTDIR)/output/host/bin
#CROSS_COMPILE=$(TOOLCHAINDIR)/arm-buildroot-linux-gnueabihf-
all clean: 
	@ctags -Rb
	@$(MAKE) -C $(topdir) $@ 2>&1 | tee log.make
