currdir=$(shell pwd)
builddir=$(currdir)/build
TARGET=test
SRCS=main.c
SRCS+=isUTF8.c
SRCS+=isASCII.c
CC=$(CROSS_COMPILE)gcc
OBJS=$(patsubst %.c,$(builddir)/%.o,$(SRCS))
CFLAGS=-Wall --save-temp -I$(currdir)/include

ifneq ($(V),)
_@=
else
_@=@
endif

all: $(builddir) $(builddir)/.fetch $(builddir)/$(TARGET)
	
$(builddir)/.fetch: 
	$(_@) cp -a $(SRCS) $(builddir)
	$(_@) touch $@

$(builddir): 
	$(_@) mkdir -p $@

$(builddir)/$(TARGET): $(OBJS)
	$(_@) $(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.c
	$(_@) cd $(builddir) && $(CC) $(CFLAGS) -o $@ -c $<

clean: 
	$(_@) rm -rf $(builddir)
	$(_@) rm -rf $(TARGET) *.[odias]

