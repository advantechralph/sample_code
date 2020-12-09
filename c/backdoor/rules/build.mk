.PHONY: build
build: prepare $(builddir)/.build


define objruletemplate
$(builddir)/$(1)/$(patsubst %.c,%.o,$(shell basename $(2))): $(builddir)/$(1)/$(shell basename $(2))
	@echo "$($(1)_cc) $($(1)_cflags) -o $$@ -c $$<"
	@$($(1)_cc) $($(1)_cflags) -o $$@ -c $$<
endef

define buildruletemplate

$(builddir)/.build_$(1): $(builddir)/$(1) \
                         $(builddir)/$(1)/.fetch_$(1) \
                         $(builddir)/$(1)/.build_$(1)

$(builddir)/$(1): 
	@mkdir -p $$@

$(builddir)/$(1)/.fetch_$(1): 
	@cp -a $($(1)_srcs) $(builddir)/$(1)
	@touch $$@

$(builddir)/$(1)/.build_$(1): $(foreach s,$($(1)_srcs),$(builddir)/$(1)/$(patsubst %.c,%.o,$(shell basename $(s)))) \
                              $(builddir)/$(1)/$($(1)_target)

$(foreach s,$($(1)_srcs),$(eval $(call objruletemplate,$(1),$(s))))

$(builddir)/$(1)/$($(1)_target): $(foreach s,$($(1)_srcs),$(builddir)/$(1)/$(patsubst %.c,%.o,$(shell basename $(s))))
	@echo "$($(1)_cc) $($(1)_cflags) -o $$@ $(foreach s,$($(1)_srcs),$(builddir)/$(1)/$(patsubst %.c,%.o,$(shell basename $(s))))"
	@$($(1)_cc) $($(1)_cflags) -o $$@ $(foreach s,$($(1)_srcs),$(builddir)/$(1)/$(patsubst %.c,%.o,$(shell basename $(s))))

endef

$(foreach t,$(targets),$(eval $(call buildruletemplate,$(t))))

$(builddir)/.build: $(foreach t,$(targets),$(builddir)/.build_$(t))

