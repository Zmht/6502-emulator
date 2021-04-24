CC=g++
CFLAGS=-std=c++17 -g
OUT=bin/main_6502

6502make: main_6502.cpp
	$(CC) $(CFLAGS) -o $(OUT) main_6502.cpp
