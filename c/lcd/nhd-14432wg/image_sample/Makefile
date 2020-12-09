currdir:=$(shell pwd)

include $(currdir)/macro.mk
include $(currdir)/rules/*.mk

.PHONY: all
all: build run
	
.PHONY: build
build: $(builddir) $(builddir)/.build

$(builddir): 
	@mkdir -p $@

$(builddir)/.build: $(builddir)/.clean_build.cmd $(builddir)/.build.cmd $(builddir)/.do_build.cmd


$(builddir)/.clean_build.cmd: 

$(builddir)/.build.cmd: 
	@echo "$(call createcmd,$(CC) $(CFLAGS) -o $(target) $(srcs),build)" > $@

$(builddir)/.do_build.cmd: 
	@/bin/bash $(builddir)/.build.cmd $(quiet)

.PHONY: run
run: 
	@$(target)

.PHONY: clean
clean: 
	@rm -rf $(builddir)


