
currdir=$(shell pwd)
builddir=${currdir}/build
SHELL=/bin/bash

# AU_HACKMD_CODE  = bfScafhcTdGzzhJ4B3evlQ
AU_HACKMD_CODE  = nqqQzpbjSCqdNyy6juF4GA
AU_OUTFILE      = $(AU_HACKMD_CODE).MD.$(shell date +%F).pdf
# AU_FORMAT: article, report and book
AU_FORMAT       = article

code:=nqqQzpbjSCqdNyy6juF4GA
outfile:=$(code).MD.$(shell date +%F).pdf
format:=article

