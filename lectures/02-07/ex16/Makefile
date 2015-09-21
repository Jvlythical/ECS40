CC=g++
CFLAGS=-Wall -ansi

TARGET=main
SOURCE=main.cpp point.cpp colorpoint.cpp  

main:	main.cpp point.cpp point.h colorpoint.cpp colorpoint.h 
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) 

