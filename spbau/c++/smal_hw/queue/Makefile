CC     = g++
CFLAGS = -Wall -Werror -c

.PHONY : clean

all : queue_test

queue_test : main.o
	$(CC) main.o -o queue_test

main.o : main.cpp rbtree.h priority_queue.h
	$(CC) main.cpp $(CFLAGS) -o main.o

clean :
	rm -f *.o queue_test
