// Создание динамической библиотеки

// В этом задании Вам необходимо создать разделяемую динамическую библиотеку libsolution.so в которой реализовать функцию со следующим прототипом:

// int stringStat(const char *string, int multiplier, int *count);


// Функция возвращает значение длины строки string, умноженное на multiplier, и увеличивает на 1 значение, на которое указывает count.

// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашей библиотеки.

// Вывод

// Программа (функция в библиотеке) ничего не выводит на консоль

// solution.c

int stringStat(const char *string, int multiplier, int *count)
{
    int stlen;
    stlen = strlen(string);
    (*count)++;
    return stlen * multiplier;
}


// Makefile

all: lib

lib: solution.c
    # gcc -shared solution.c -o libsolution.so
    gcc -shared solution.c -fPIC -o libsolution.so

clean:
    -rm -f libsolution.so 2>/dev/null