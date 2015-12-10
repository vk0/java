// Задача 5. Соберите Makefile?
// http://habrahabr.ru/post/155201/

CC=gcc
all: hello
hello: hello.o
$(CC) -o hello hello.o
hello.o: hello.c
$(CC) -c hello.c

