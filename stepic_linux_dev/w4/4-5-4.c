// Поиск пути к init по заданному pid

// Разработать программу solution, которая по заданному pid, осуществляет поиск пути в дереве процессов до процесса с идентификатором 1 (init). Для каждого найденного процесса печатается в отдельной строке его идентификатор.

// Пример вызова

// ./solution 1766
// 1766
// 1299
// 465
// 1


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода числа (каждое число в отдельной строке)

#include <stdio.h>
#include <string.h>
#include <linux/limits.h>

int read_proc(int pid) {
    char fname[255];
    FILE *input;
    int ppid;
    char tcomm[PATH_MAX];
    char state;

    sprintf(fname, "/proc/%i/stat", pid);
    input = fopen(fname, "r");

    fscanf(input, "%i %s %c %i", &pid, tcomm, &state, &ppid);
    fclose(input);
    return ppid;
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        return -1;
    int pid, ppid;
    int init_pid = 1;
    sscanf(argv[1], "%i", &pid);
    printf("%i\n", pid);
    ppid = read_proc(pid);
    while (ppid != init_pid) {
        printf("%i\n", ppid);
        ppid = read_proc(ppid);
    }
    printf("%i\n", init_pid);
    return 0;
}