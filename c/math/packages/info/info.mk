
.PHONY: info
info: packages/info/build

.PHONY: packages/info/build
packages/info/build: 
	@printf "\n"
	@printf "%-30s: %s\n" "currdir" "$(currdir)"
	@printf "%-30s: %s\n" "builddir" "$(builddir)"
	@printf "\n"

