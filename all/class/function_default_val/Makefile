
CC=gcc
CXX=g++
CFLAGS=-Wall
TARGET=sample
LIBS=

all: clean
	@$(CXX) $(LDFLAGS) $(CFLAGS) -o $(TARGET) *.cpp --save-temp $(LIBS)
#	@./$(TARGET)

clean: 
	@rm -rf $(TARGET)
	@rm -rf *.[ios] *.ii
