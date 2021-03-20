CC= g++
CFLAGS= -g -Wall -Werror -pedantic -O3 -std=c++0x
Boost= -lboost_unit_test_framework

all:	ps3a main.out

ps3a:	test.o CircularBuffer.o
	$(CC) test.o CircularBuffer.o -o ps3a $(Boost)

main.out:  main.o CircularBuffer.o
	$(CC) main.o CircularBuffer.o -o main.out

CircularBuffer.o:  CircularBuffer.cpp CircularBuffer.h
	$(CC) -c CircularBuffer.cpp CircularBuffer.h $(CFLAGS)

test.o:	test.cpp CircularBuffer.h
	$(CC) -c test.cpp CircularBuffer.h $(CFLAGS)

main.o: main.cpp CircularBuffer.h
	$(CC) -c main.cpp CircularBuffer.h $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm *.out
	rm ps3a
