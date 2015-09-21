CC=g++
CFLAGS=-Wall -ansi -g

TARGET=mscp
SOURCE=mscp.cc board.cc

mscp: mscp.cc board.cc board.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) 

clean:
	rm -f $(TARGET)
