// Разбор аргументов командной строки

// Требуется написать программу solution, выполняющую разбор опций командной строки и выводящую в стандартный поток вывода символ '+', если набор корректен, или '-' в противном случае.

// Описание возможных опций:

//     -q | --query (обязательный, требует аргумента опции)
//     -i | --longinformationrequest (опциональный)
//     -v | --version (опциональный)


// Пример вызова

// ./solution -q 9 --version
// +


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит символ корректности опций командной строки

// solution.c
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main (int argc, char **argv) {
    int c;
    int res = 1;
    while (1) {
        static struct option long_options[] =
        {
            {"query",   required_argument, 0, 'q'},
            {"longinformationrequest",  no_argument, 0, 'i'},
            {"version", no_argument, 0, 'v'},
            {0, 0, 0, 0}
        };
        int option_index = 0;

        c = getopt_long (argc, argv, "q:iv", long_options, &option_index);
        if (c == 63) {
            res = 0;
            break;
        }
        if (c == -1)
            break;
    }
    if (res)
        printf("+\n");
    else
        printf("-\n");
    exit (0);
}

// Makefile

all:    exe
exe:    solution.c
    gcc -o solution  solution.c