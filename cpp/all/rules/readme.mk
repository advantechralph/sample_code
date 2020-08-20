
define readme_str

 ================================================
 =        MAKE ALL C/CPP SOURCE README          =
 ================================================

  - Compile source code and run it

    $$ make run

endef
export readme_str
.PHONY: readme
readme: 
	@echo "$${readme_str}"
