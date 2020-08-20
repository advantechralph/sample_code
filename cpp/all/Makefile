include macro.mk
include rules/*.mk

runs=main_c

run all: $(runs)

$(foreach t,$(c_targets) $(cpp_targets),$(eval $(call targetrule,$(t))))

