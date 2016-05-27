// Подсчет числа процессов с заданным именем

// Разработать программу solution, которая осуществляет поиск и подсчет числа процессов с именем genenv﻿ в системе Linux на которой выполняется программа.

// Пример вызова

// ./solution
// 13


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку

// solution.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main( int argc, char *argv[] ) {
    DIR* proc = opendir("/proc");
    struct dirent* ent;
    long tgid;
    char path[40], line[100];
    FILE* commf;
    int count = 0;
    if (proc == NULL) {perror("opendir(/proc)"); return 1;}
    while (ent = readdir(proc)) {
        if (!isdigit(*ent->d_name))
            continue;
        tgid = strtol(ent->d_name, NULL, 10);
        snprintf(path, 40, "/proc/%ld/comm", tgid);
        commf = fopen(path, "r"); if (!commf) return;
        while (fgets(line, 100, commf)) {
            if (strncmp(line, "genenv", 6) != 0)
                continue;
            count++;
        }
        fclose(commf);
    }
    printf("%d\n", count);
    closedir(proc);
}


// Makefile

all:    exe
exe:    solution.c
    gcc solution.c -o solution