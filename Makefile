CC=g++
CFLAGS=-std=c++17 -g
TARGET=bin/main_6502


6502make: main_6502.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main_6502.cpp


clean: 
	-rm -f $(TARGET