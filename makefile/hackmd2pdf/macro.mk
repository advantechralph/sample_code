
currdir=$(shell pwd)
builddir=${currdir}/build
SHELL=/bin/bash

AU_HACKMD_CODE  = bfScafhcTdGzzhJ4B3evlQ
AU_OUTFILE      = $(builddir)/$(AU_HACKMD_CODE).MD.$(shell date +%F).pdf
AU_FORMAT       = article

