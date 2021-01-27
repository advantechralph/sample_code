
define bar
$(shell printf "#%.0s" {1..47}; echo)
endef

define usage_str

$(call bar)
# Make pdf from HackMD
$(call bar)

Usage: 

  $$ make [target] [parameter: <ENV1=VAR1> <ENV2=VAR2> ... ]

    Build target by makefile rules. 

    target: 

      <empty>                        Default target, show this usage.
      hackmd2pdf                     Convert HachMD md file to pdf. 
                                                               
    parameter:                                                 

      AU_HACKMD_CODE                 HackMD hash code. 
                                                               
  --------

endef
export usage_str

usage help: 
	@echo "$${usage_str}" | more

