
include $(topdir)/rules/dumpvars.mk

ifeq ($(PACKAGE_TARGET),)
PACKAGE_TARGET:=$(PACKAGE)
endif

ifeq ($(PACKAGE_SOURCES),)
PACKAGE_SOURCES:=$(builddir)/packages/$(PACKAGE)/$(notdir $(wildcard $(topdir)/packages/$(PACKAGE)/files/*.c))
endif

$(info PACKAGE_SOURCES=$(PACKAGE_SOURCES))
PACKAGE_OBJS:=$(patsubst %.c,%.o,$(PACKAGE_SOURCES))
$(info PACKAGE_OBJS=$(PACKAGE_OBJS))

define package_rules

.PHONY: packages/$(PACKAGE)/build
packages/$(PACKAGE)/build: $(builddir)/packages/$(PACKAGE)/.build
	@echo $$@ done

$(builddir)/packages/$(PACKAGE): 
	@mkdir -p $$@

$(builddir)/packages/$(PACKAGE)/.build: packages/$(PACKAGE)/fetch packages/$(PACKAGE)/compile

.PHONY: packages/$(PACKAGE)/fetch
packages/$(PACKAGE)/fetch: $(builddir) $(builddir)/packages/$(PACKAGE) $(builddir)/packages/$(PACKAGE)/.fetch
	@echo $$@ done
	
$(builddir)/packages/$(PACKAGE)/.fetch: 
	@tar -C packages/$(PACKAGE)/files --numeric-owner -zcpf - . | tar -C $(builddir)/packages/$(PACKAGE) -zxpf - 
	@touch $$@

.PHONY: packages/$(PACKAGE)/compile
packages/$(PACKAGE)/compile: $(builddir)/packages/$(PACKAGE)/$(PACKAGE_TARGET)

$(builddir)/packages/$(PACKAGE)/$(PACKAGE_TARGET): $(PACKAGE_OBJS)
	@$(PACKAGE_CC) $(PACKAGE_LFLAGS) $(PACKAGE_CFLAGS) -o $(builddir)/packages/$(PACKAGE)/$(PACKAGE_TARGET) $(PACKAGE_OBJS) $(PACKAGE_LIBS)

.PHONY: packages/$(PACKAGE)/clean
packages/$(PACKAGE)/clean: 
	@rm -rf $(builddir)/packages/$(PACKAGE)

endef

define package_cobjs_rules

$(patsubst %.c,%.o,$(1)): $(1)
	@$(PACKAGE_CC) $(PACKAGE_CFLAGS) -o $$@ -c $$<

endef

$(foreach S,$(PACKAGE_SOURCES),$(eval $(call package_cobjs_rules,$(S))))

define package_rules_dump

define packages_$(PACKAGE)_rules
$(call package_rules)
$(foreach S,$(PACKAGE_SOURCES),$(call package_cobjs_rules,$(S)))
endef

export packages_$(PACKAGE)_rules

.PHONY: packages/$(PACKAGE)/rules
packages/$(PACKAGE)/rules:
	@echo "$$$${packages_$(PACKAGE)_rules}"

endef

$(eval $(call package_rules))
$(eval $(call package_rules_dump))

