// Run-time компоновка

// Разработать программу solution, обеспечивающую загрузку динамической библиотеки в режиме исполнения. При запуске, программе передается имя динамической библиотеки, имя функции которая должна быть вызвана, и ее аргумент. Функция в библиотеке принимает на вход int и возвращает int. Результат, возвращаемый функций должен быть выведен отдельной строкой  в stdio.

// Пример вызова

// ./solution libShared.so someSecretFunctionPrototype 8
// 16

// В примере, должна быть загружена библиотека libShared.so, в которой вызвана функция someSecretFunctionPrototype с аргументом 8. Результат (16) выведен в stdio.


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число, полученное после вызова функции

// solution.c
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int (*func)(int);

bool init_library(char *lib_name, char *func_name) {
    void *hdl = dlopen(lib_name, RTLD_LAZY);
    if (NULL == hdl)
        return false;
    func = (int (*)(int))dlsym(hdl, func_name);
    if (NULL == func)
        return false;
    return true;
}

int main(int argc, char *argv[]) {
    if (init_library(argv[1], argv[2])) {
        int value = atoi(argv[3]);
        printf("%d\n", func(value));
    }
    else
        printf("error");
    return 0;
}

// Makefile

all:    exe
exe:    solution.c
    gcc solution.c -Wl,-rpath=./ -fPIC -ldl -o solution
