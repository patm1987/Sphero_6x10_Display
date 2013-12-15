
CC=g++
CFLAGS=-Wall -I. -std=c++11
SOURCES=Testing/main.cpp Testing/GLDisplayMatrix.cpp
OUT=testing

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)

clean:
	rm -rf $(OUT)