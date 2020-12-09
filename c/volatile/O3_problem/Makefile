
CC=gcc
CFLAGS=-Wall

all: 
	@$(CC) $(CFLAGS) -o sample sample.c --save-temp
	@$(CC) $(CFLAGS) -O3 -o sample2 sample2.c --save-temp
	@$(CC) $(CFLAGS) -o sample3 sample3.c --save-temp
	@./sample
	@./sample2
	@./sample3

clean: 
	@rm -rf sample sample2 sample3
	@rm -rf *.[ios]
