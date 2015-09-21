CC=g++
CFLAGS=-Wall -ansi -g

TARGET=mscp
SOURCE=mscp.cpp board.cpp

mscp: mscp.cpp board.cpp board.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) 

clean:
	rm -f $(TARGET)
