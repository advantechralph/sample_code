
ifeq ($(modelname),dummy)
define usage_str

  Dummy project usage: 

endef
export usage_str

usage help: 
	@echo "$${usage_str}" | more
endif

