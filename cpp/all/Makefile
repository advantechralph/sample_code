

#ifeq ($(_REALRUN),1)
ifdef _REALRUN

include macro.mk
include rules/*.mk

#runs=ListNode_cpp string_cpp container_cpp binarySearch_cpp
runs=binarySearch_cpp string_cpp

run all: $(runs)

$(foreach t,$(c_targets) $(cpp_targets),$(eval $(call targetrule,$(t))))

else
export _REALRUN=1
.DEFAULT_GOAL:=readme
_MAKEFILE=$(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
_MAKEFLAGS=$(filter-out --,$(MAKEFLAGS))

define realrun
  @ [ -z "$(shell which time)" ] \
    && time make -f $(_MAKEFILE) $1 $(filter-out --,$(_MAKEFLAGS)) 2>&1 | tee log \
    || make -f $(_MAKEFILE) $1 $(filter-out --,$(_MAKEFLAGS)) 2>&1  | tee log; \

endef

%: 
	$(call realrun,$@)

endif

