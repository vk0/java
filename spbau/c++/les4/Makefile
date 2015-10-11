CC = g++
FLAGS = -Werror

array : array.o main.o
	$(CC) $(FLAGS) array.o main.o -o array

main.o : main.cpp array.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

array.o : array.cpp array.h
	$(CC) $(FLAGS) -c array.cpp -o array.o

default : array

clean :
	rm -f *.o array

.PHONY : clean
