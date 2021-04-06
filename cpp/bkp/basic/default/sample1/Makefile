outdir=$(PWD)/output
srcdir=$(PWD)/srcs
target=$(outdir)/sample
srcs=$(foreach _f,$(foreach _suffix,c cpp,$(wildcard $(srcdir)/*.$(_suffix))),$(notdir $(_f)))
objs=$(foreach _s,$(srcs),$(outdir)/$(basename $(_s)).o)
CXXFLAGS=-Wall -I$(PWD)/include
LDFALGS=
define srcsuffix
$(basename $(1))_srcsuffix=$(suffix $(1))
endef
define cpprules
$(outdir)/$(notdir $(basename $(1)).o): $(srcdir)/$(notdir $(basename $(1))$($(basename $(1))_srcsuffix))
	$(strip $(CXX) $(CXXFLAGS) -o $(outdir)/$(notdir $(basename $(1)).o) -c $(srcdir)/$(notdir $(basename $(1))$($(basename $(1))_srcsuffix)))
endef
$(foreach _s,$(srcs),$(eval $(call srcsuffix,$(_s))))

all: $(target)

$(target): $(outdir) $(objs)
	$(strip $(CXX) $(LDFLAGS) -o $@ $(objs))

$(outdir):
	 @mkdir -p $@

clean:
	@rm -rf $(outdir)

$(foreach _s,$(srcs),$(eval $(call cpprules,$(_s))))

