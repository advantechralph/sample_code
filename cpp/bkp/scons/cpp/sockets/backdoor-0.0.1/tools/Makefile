APPDIR=$(shell realpath $(shell pwd)/..)
include $(APPDIR)/Rules.mk
OBJS=$(patsubst %.c,$(TARGETOUTPUTDIR)/%.o,${wildcard *.c})

all: $(TARGETOUTPUTDIR) $(OBJS)

clean:
	@rm -rf $(OBJS)
