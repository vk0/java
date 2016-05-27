// Поиск ppid c использованием procfs

// Разработать программу solution, которая осуществляет поиск родительского PID текущего процесса в файловой системе proc и выводит найденное значение на консоль.  Результат, возвращаемый функций должен быть выведен отдельной строкой  в stdio.

// Пример вызова

// ./solution
// 13221


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку

// solution.c

#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

typedef long long int num;
num pid;
num ppid;
char tcomm[PATH_MAX];
char state;

FILE *input;

int main(int argc, char *argv[]) {
    input = NULL;
    input = fopen("/proc/self/stat", "r");
    fscanf(input, "%lld %s %c %lld ", &pid, tcomm, &state, &ppid);
    printf("%lld\n", ppid);
    return 0;
}

// #include <stdio.h>
// #include <unistd.h>
// #include <linux/limits.h>

// typedef long long int num;
// num pid;
// char tcomm[PATH_MAX];
// char state;
// num ppid;

// FILE *input;

// void readone(num *x) { fscanf(input, "%lld ", x); }
// void readstr(char *x) { fscanf(input, "%s ", x);}
// void readchar(char *x) { fscanf(input, "%c ", x);}
// void printone(num x) { printf("%lld\n", x);}

// int main(int argc, char *argv[]) {
//     input = NULL;
//     input = fopen("/proc/self/stat", "r");
//     if (!input) {
//         perror("open");
//         return 1;
//     }
//     readone(&pid);
//     readstr(tcomm);
//     readchar(&state);
//     readone(&ppid);
//     {
//         printone(ppid);
//     }
//     return 0;
// }


// Makefile

all:    exe
exe:    solution.c
    gcc solution.c -o solution
