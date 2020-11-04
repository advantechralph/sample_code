currdir=$(shell pwd)
builddir=$(currdir)/build
srcdir=$(currdir)/src
TARGET=test
.PHONY: all $(TARGET) clean
all: $(builddir) $(TARGET)

$(TARGET): 
	@cd $(builddir) && $(CC) -Wall -DPC_SIM -o $@ $(srcdir)/*.c

clean: 
	@rm -rf $(builddir)
	@rm -rf $(TARGET) *.o

$(builddir): 
	@mkdir -p $@
