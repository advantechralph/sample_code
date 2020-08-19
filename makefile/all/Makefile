
.DEFAULT_GOAL:=usage
default: usage;

C_FILES=$(wildcard *.c)
O_FILES=$(patsubst %.c,%.o,$(C_FILES))
TARGET_FILES=$(patsubst %.c,%,$(C_FILES))
downloadurl=http://www.test.com/download/this-is-your-download-file.tar.gz
downloadfile=$(shell $(call packedfilename,$(downloadurl)))
CFLAGS=-Wall --save-temp
LIBS=-lpthread

define packedfilename
_u=$(1); echo $${_u##*/}; 
endef

define objtargets
.PHONY: $(1)
$(1): build_$(1) run_$(1)

.PHONY: build_$(1)
build_$(1): $(PWD)/build/build_$(1)

.PHONY: $(PWD)/build/build_$(1)
$(PWD)/build/build_$(1): 
	@mkdir -p $(PWD)/build
	@cd $(PWD)/build/ && gcc $(CFLAGS) -o $(PWD)/build/$(1) $(PWD)/$(1).c $(LIBS)

.PHONY: run_$(1)
run_$(1): 
	@$(PWD)/build/$(1)

.PHONY: clean_$(1)
clean_$(1): 
	@rm -rf $(PWD)/build/$(1)

endef

clean: 
	@rm -rf $(PWD)/build


$(foreach t,$(TARGET_FILES),$(eval $(call objtargets,$(t))))

define usage_str
All Makefile sample usage: 

    make info                         show infomation


endef

export usage_str

all: 
	@echo $@ target
info: 
	@echo C_FILES=$(C_FILES)
	@echo O_FILES=$(O_FILES)
	@echo TARGET_FILES=$(TARGET_FILES)
	@echo downloadurl=$(downloadurl)
	@echo downloadfile=$(downloadfile)

usage: 
	@echo "$${usage_str}"

