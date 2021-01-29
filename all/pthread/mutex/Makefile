
CC=gcc
CFLAGS=-Wall
TARGET=sample
LIBS=-lpthread

all: 
	@$(CC) $(LDFLAGS) $(CFLAGS) -o $(TARGET) *.c --save-temp $(LIBS)
#	@./$(TARGET)

clean: 
	@rm -rf $(TARGET)
	@rm -rf *.[ios]
