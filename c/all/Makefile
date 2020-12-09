
.DEFAULT_GOAL:=all
default: all;

CC=gcc
CFLAGS=-Wall --save-temp
LIBS=-lpthread

C_FILES=$(wildcard *.c)
O_FILES=$(patsubst %.c,%.o,$(C_FILES))
TARGET_FILES=$(patsubst %.c,%,$(C_FILES))

define objtargets
.PHONY: $(1)
$(1): build_$(1)

.PHONY: build_$(1)
build_$(1): $(PWD)/build/build_$(1)

.PHONY: $(PWD)/build/build_$(1)
$(PWD)/build/build_$(1): 
	@mkdir -p $(PWD)/build
	@cd $(PWD)/build/ && $(CC) $(CFLAGS) -o $(PWD)/build/$(1) $(PWD)/$(1).c $(LIBS)

.PHONY: run_$(1)
run_$(1): build_$(1) $(PWD)/build/run_$(1)

.PHONY: $(PWD)/build/run_$(1)
$(PWD)/build/run_$(1): 
	@echo run '$(1)'...
	@$(PWD)/build/$(1)

.PHONY: clean_$(1)
clean_$(1): 
	@rm -rf $(PWD)/build/$(1)

endef


TARGETS=power

RUNS=$(foreach r,$(TARGETS),$(patsubst %,run_%,$(r)))

all: $(RUNS)

clean: 
	@rm -rf $(PWD)/build

$(foreach t,$(TARGET_FILES),$(eval $(call objtargets,$(t))))
