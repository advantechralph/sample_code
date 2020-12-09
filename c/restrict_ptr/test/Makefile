
CC=gcc
CFLAGS=-Wall
CFLAGS+=-O3 -fstrict-aliasing -std=c99

all: 
	@$(CC) $(CFLAGS) -o sample *.c --save-temp
	@./sample

clean: 
	@rm -rf sample
	@rm -rf *.[ios]
