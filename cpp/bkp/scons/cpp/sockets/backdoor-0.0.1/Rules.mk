APPDIR?=$(shell realpath $(shell pwd))
prefix?=/usr
TARGET?=bd_svr
OUTPUTDIR=$(shell realpath $(APPDIR)/output)
TARGETOUTPUTDIR=$(OUTPUTDIR)/$(TARGET)
DESTDIR?=$(OUTPUTDIR)
INSTALL_CLI_DIR=/bin
all:
$(TARGETOUTPUTDIR)/%.o: %.c
	$(CC) $(TARGETCFLAGS) $(CFLAGS) -o $@ -c $(filter %.c,$^)
$(TARGETOUTPUTDIR):
	@mkdir -p $@
