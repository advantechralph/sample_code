
CC=gcc
CFLAGS=-Wall
#CFLAGS+=-finstrument-functions

all: build/sample run

build/sample: 
	@mkdir -p build 
	@cd build && $(CC) $(CFLAGS) -o sample ../*.c --save-temp

clean: 
	@rm -rf build
	@rm -rf sample
	@rm -rf *.[ios]

run: ;@cd build && ./sample
