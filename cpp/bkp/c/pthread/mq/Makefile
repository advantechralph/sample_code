outdir=$(PWD)/output
srcdir=$(PWD)/srcs
target=$(outdir)/sample
srcs=$(foreach _f,$(foreach _suffix,c cpp,$(wildcard $(srcdir)/*.$(_suffix))),$(notdir $(_f)))
objs=$(foreach _s,$(srcs),$(outdir)/$(basename $(_s)).o)
CFLAGS=-Wall -I$(PWD)/include
LDFALGS=
LIBS=-lpthread -lrt
define srcsuffix
$(basename $(1))_srcsuffix=$(suffix $(1))
endef
define cpprules
$(outdir)/$(notdir $(basename $(1)).o): $(srcdir)/$(notdir $(basename $(1))$($(basename $(1))_srcsuffix))
	$(strip $(CC) $(CFLAGS) -o $(outdir)/$(notdir $(basename $(1)).o) -c $(srcdir)/$(notdir $(basename $(1))$($(basename $(1))_srcsuffix)))
endef
$(foreach _s,$(srcs),$(eval $(call srcsuffix,$(_s))))

all: $(target) run

$(target): $(outdir) $(objs)
	$(strip $(CC) $(LDFLAGS) -o $@ $(objs) $(LIBS))

$(outdir):
	 @mkdir -p $@

clean:
	@rm -rf $(outdir)

run:
	@$(target)

$(foreach _s,$(srcs),$(eval $(call cpprules,$(_s))))

