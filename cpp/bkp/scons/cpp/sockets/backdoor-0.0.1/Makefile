APPDIR=$(shell realpath $(shell pwd))
include $(APPDIR)/Rules.mk
targets=svr cli
makes=$(patsubst %,_make_%,$(targets))
all: $(makes)
clean: 
	@rm -rf $(OUTPUTDIR)
_make_%:
	@make -f $(patsubst _make_%,%,$@).mk
install: $(DESTDIR)/$(prefix)/bin
	@cp -a $(TARGETOUTPUTDIR)/bd_svr  $(DESTDIR)/$(prefix)/bin
$(DESTDIR)/$(prefix)/bin:;@mkdir -p $@
