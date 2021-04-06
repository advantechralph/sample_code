APPDIR=$(shell realpath $(shell pwd))
TARGET=bd_svr
include $(APPDIR)/Rules.mk
DIRS=tools socket_tools handle cmd_tools
_makes_=$(patsubst %,_make_%,$(DIRS))
_cleans_=$(patsubst %,_clean_%,$(DIRS))
OBJS=$(TARGETOUTPUTDIR)/svr.o
CFLAGS+=-I$(APPDIR)/include
LDFLAGS=-static
all: $(TARGETOUTPUTDIR) $(_makes_) $(OBJS)
	@$(CC) $(LDFLAGS) $(CFLAGS) -o $(TARGETOUTPUTDIR)/$(TARGET) $(wildcard $(TARGETOUTPUTDIR)/*.o)
clean: $(_cleans_)
_make_%:
	make -C $(patsubst _make_%,%,$@)
_clean_%: 
	make -C $(patsubst _clean_%,%,$@) clean

