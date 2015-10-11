CC=g++
FLAGS=-Wall -v

program : main.o foo.o
	$(CC) main.o foo.o -o program

foo.o : foo.cpp foo.h
	$(CC) -c $(FLAGS) foo.cpp

main.o : main.cpp foo.h
	$(CC) -c $(FLAGS) main.cpp

clean:
	rm -f *.o

default: program

.PHONY: clean program
