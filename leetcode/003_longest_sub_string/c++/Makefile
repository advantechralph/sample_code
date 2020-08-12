currdir:=$(shell pwd)

include $(currdir)/macro.mk
include $(currdir)/rules/*.mk

.PHONY: all
all: build test
	
.PHONY: build
build: $(builddir) $(builddir)/.build

.PHONY: test
test: 
	@$(target)

$(builddir): 
	@mkdir -p $@

$(builddir)/.build: $(builddir)/.clean_build.cmd $(builddir)/.build.cmd $(builddir)/.do_build.cmd


$(builddir)/.clean_build.cmd: 

$(builddir)/.build.cmd: 
	@echo "$(call createcmd,$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $(target) $(srcs),build)" > $@

$(builddir)/.do_build.cmd: 
	@. $(builddir)/.build.cmd $(quiet)

.PHONY: clean
clean: 
	@rm -rf $(builddir)


