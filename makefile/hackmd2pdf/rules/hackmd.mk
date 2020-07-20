
.PHONY: hackmd2pdf
hackmd2pdf: $(builddir)
	@echo format doc
	curl -s -L "https://hackmd.io/$(AU_HACKMD_CODE)/download" \
	-o /tmp/$(AU_HACKMD_CODE).md
	pandoc /tmp/$(AU_HACKMD_CODE).md -o $(AU_OUTFILE) \
		--table-of-contents \
		--latex-engine=xelatex \
		--highlight-style=monochrome \
		--number-sections \
		-V 'fontsize: 12pt' \
		-V 'papersize: A4' \
		-V 'urlcolor: blue' \
		-V 'date: \today{}' \
		-V 'documentclass:$(AU_FORMAT)' \
		-V 'geometry:margin=3.8cm'
	xdg-open $(AU_OUTFILE)
	@echo done

