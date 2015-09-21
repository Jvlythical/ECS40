CC=g++
CFLAGS=-Wall -ansi

TARGET=main
SOURCE=main.cpp Interface.cpp

main:	main.cpp Interface.cpp Interface.h Implementation.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) 

