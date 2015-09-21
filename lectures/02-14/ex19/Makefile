CC=g++
CFLAGS=-Wall -ansi

TARGET1=main
SOURCE1=main.cpp 

TARGET2=swap
SOURCE2=swap.cpp 

TARGET3=sort
SOURCE3=sort.cpp 

TARGETS=$(TARGET1) $(TARGET2) $(TARGET3)

main:	main.cpp
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

swap: 	swap.cpp
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)

sort: 	sort.cpp
	$(CC) $(CFLAGS) -o $(TARGET3) $(SOURCE3)

clean:
	rm -f $(TARGETS) 

