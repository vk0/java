// Подсчет числа процессов с заданным именем

// Разработать программу solution, которая осуществляет поиск и подсчет числа процессов с именем genenv﻿ в системе Linux на которой выполняется программа.

// Пример вызова

// ./solution
// 13


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку

#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

typedef long long int num;
num pid;
char tcomm[PATH_MAX];
char state;
num ppid;

FILE *input;

int main(int argc, char *argv[]) {
    input = NULL;
    input = fopen("/proc/self/stat", "r");
    fscanf(input, "%lld %s %c %lld ", &pid, tcomm, &state, &ppid);
    printf("%lld\n", ppid);
    return 0;
}