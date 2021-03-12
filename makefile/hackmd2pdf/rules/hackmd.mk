
.PHONY: hackmd2pdf
hackmd2pdf: $(builddir) $(builddir)/$(outfile)

$(builddir)/$(code).md: 
	@curl -s -L "https://hackmd.io/$(code)/download" -o $(builddir)/$(code).md

$(builddir)/$(outfile): $(builddir)/$(code).md
	@pandoc $< -o $@ \
		--table-of-contents \
		--latex-engine=xelatex \
		--highlight-style=monochrome \
		--number-sections \
		-V 'fontsize: 12pt' \
		-V 'papersize: A4' \
		-V 'urlcolor: blue' \
		-V 'date: \today{}' \
		-V 'documentclass:$(format)' \
		-V 'geometry:margin=3.8cm'
#	xdg-open $(outfile)

md2pdf: $(builddir)
	@pandoc $(builddir)/$(code).md -o $(builddir)/$(outfile) \
		--table-of-contents \
		--latex-engine=xelatex \
		--highlight-style=monochrome \
		--number-sections \
		-V 'fontsize: 12pt' \
		-V 'papersize: A4' \
		-V 'urlcolor: blue' \
		-V 'date: \today{}' \
		-V 'documentclass:$(format)' \
		-V 'geometry:margin=3.8cm'

test:
	@cd $(builddir) && \
		pandoc --listings -H listings-setup.tex \
			--latex-engine=xelatex \
			--toc -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" -V fontsize=12pt test.md -o test.pdf


