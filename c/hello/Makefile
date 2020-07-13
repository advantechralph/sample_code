currdir:=$(shell pwd)

include $(currdir)/macro.mk
include $(currdir)/rules/*.mk

.PHONY: all
all: build
	
.PHONY: build
build: $(builddir) $(builddir)/.build

$(builddir): 
	@mkdir -p $@

$(builddir)/.build: $(builddir)/.clean_build.cmd $(builddir)/.build.cmd $(builddir)/.do_build.cmd

define logncmd
  logT=$(builddir)/log-$$(date +"%F_%T")$(shell basename $(patsubst %.cmd,%,$(2))); \
  log=$(builddir)/log$$(basename $(patsubst %.cmd,%,$(2))); \
  rm -rf \$${logT}; \
  ln -sf \$${logT} \$${log}; \
  exec > >(tee -i -a \$${logT}); \
  exec 2>&1; \
  set -x; \
  $(1); \
  exit 0; 
endef

$(builddir)/.clean_build.cmd: 

$(builddir)/.build.cmd: 
	@echo "$(call logncmd,$(CC) $(CFLAGS) -o $(target) $(srcs),$@)" > $@

$(builddir)/.do_build.cmd: 
	@. $(builddir)/.build.cmd $(quiet)

.PHONY: clean
clean: 
	@rm -rf $(builddir)


