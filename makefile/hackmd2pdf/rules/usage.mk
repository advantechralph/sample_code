
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

      code                 HackMD hash code. 
	  format               pandoc format: article(default), report and book. 

   examples:

     $$ make code=pK83NesKQ2Oijo4n0EZURQ info
     $$ make code=pK83NesKQ2Oijo4n0EZURQ hackmd2pdf
     $$ make code=pK83NesKQ2Oijo4n0EZURQ hackmd2pdf format=report
                                                               
  --------

endef
export usage_str

usage help: 
	@echo "$${usage_str}" | more

