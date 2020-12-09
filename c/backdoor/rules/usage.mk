
define bar
$(shell printf "#%.0s" {1..47}; echo)
endef

define usage_str

$(call bar)
# Backdoor Tools Builder
$(call bar)

Usage: 

  $$ make [target]

    Build target by makefile rules. 

    target: 

      <empty>
          Show this usage.
      build  
          Build backddor utilities. 
                                                               
endef
export usage_str

usage help: 
	@echo "$${usage_str}" | more

