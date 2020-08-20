
define targetrule
ifeq ($(patsubst %_c,c,$(1)),c)
$(1)_compiler?=gcc
$(1)_cflags?=$(cflags)
define $(1)_compile_recipe
  @ \
    cd $(builddir) && \
    $$($(1)_compiler) $$($(1)_cflags) -o $(builddir)/$(1) $$(call prependpath,$$($(1)_srcs),$(srcsdir))
endef
define $(1)_clean_recipe
  @ \
    rm -rf $(builddir)/$$($(1)_target); \
    rm -rf $(builddir)/$$($(1)_target).[ios]; \
    
endef
define $(1)_run_recipe
  @ echo run $(1)...; \
    $(builddir)/$(1)
endef
endif
ifeq ($(patsubst %_cpp,cpp,$(1)),cpp)
$(1)_compiler?=g++
$(1)_cflags?=$(cxxflags)
define $(1)_compile_recipe
  @ \
    cd $(builddir) && \
    $$($(1)_compiler) $$($(1)_cflags) -o $(builddir)/$(1) $$(call prependpath,$$($(1)_srcs),$(srcsdir))
endef
define $(1)_clean_recipe
  @ \
    rm -rf $(builddir)/$$($(1)_target); \
    rm -rf $(builddir)/$$($(1)_target).[ios]; \
    
endef
define $(1)_run_recipe
  @ echo run $(1)...; \
    $(builddir)/$(1)
endef
endif
$(1)_srcs?=$(subst _,.,$(1))

.PHONY: $(1)
$(1): builddir $(builddir)/.build_$(1) run_$(1)
	
.PHONY: $(builddir)/.build_$(1)
$(builddir)/.build_$(1): $(builddir)/.compile_$(1) $(builddir)/.build_$(1)_done

.PHONY: $(builddir)/.compile_$(1)
$(builddir)/.compile_$(1): 
	$$(call $(1)_compile_recipe)

.PHONY: clean_$(1)
clean_$(1):
	$$(call $(1)_clean_recipe)

.PHONY: run_$(1)
run_$(1):
	$$(call $(1)_run_recipe)

.PHONY: $(builddir)/.build_$(1)_done
$(builddir)/.build_$(1)_done: 
	@echo build $(1) done!!

endef
