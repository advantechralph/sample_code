
.PHONY: info
info: 
	@printf "\n"
	@printf "%-30s: %s\n" "currdir" "$(currdir)"
	@printf "%-30s: %s\n" "AU_HACKMD_CODE" "$(AU_HACKMD_CODE)"
	@printf "%-30s: %s\n" "AU_OUTFILE" "$(AU_OUTFILE)"
	@printf "\n"

