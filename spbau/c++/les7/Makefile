CC=g++
FLAGS=-Werror

test : object.o autoptr.o main.o
	$(CC) $(FLAGS) object.o autoptr.o main.o -o test

object.o : object.cpp
	$(CC) $(FLAGS) -c object.cpp -o object.o

autoptr.o : autoptr.cpp
	$(CC) $(FLAGS) -c autoptr.cpp -o autoptr.o

main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp -o main.o

clean :
	rm -f *.o test

.PHONY : clean
