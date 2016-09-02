// Напишите на языке C / C++ программу, определяющую номер треугольного числа (см. также последовательность A000217 в «Энциклопедии целочисленных последовательностей»).

// Примечание: число 0 (ноль) не считается принадлежащим ряду, который считается начинающимся с единицы: 1, 3, 6, 10, 15, 21, 28, ... ﻿

// Вход: одно целое (возможно, со знаком «плюс» и символом «перевод строки» \n) число в диапазоне от 1 до 9'223'372'036'854'775'807.

// Выход: порядковый номер поданного на вход числа в последовательности треугольных чисел или 0 (ноль), если такого числа в последовательности нет. Символ 0 (ноль) должен выдаваться и во всех случаях подачи на вход некорректных (отрицательных и лежащих вне допустимого диапазона положительных числовых, а также символьных / строковых) данных.

// Sample Input:
// 10
// Sample Output:
// 4

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;


int main()
{
    unsigned long long int StartNumber = 0, Input = 0, Output = 0;
    long double FinalNumber = 9223372036854775807;

    cin >> Input;
    if (Input > 0 && Input <= FinalNumber) {
        for (int i = 0; i <= Input; i++)
        {
            StartNumber = StartNumber + i;
            if (StartNumber == Input) {
                Output = i;
                cout << Output;
                break;
            }
        }
        if (!Output)
            cout << 0;
    }
    elsez
        cout << 0;
    cin.get();
    cin.get();
    return 0;
}


// =====
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

enum {
    MAX_COUNT = 20,
    BUFF_LENGTH = MAX_COUNT + 1
};

long position (long long);
long long getTriang ();

int main(int argc, char **argv)
{
    printf("%Li\n", position(getTriang()));

    return 0;
}

long position (long long triangle)
{
    if (triangle < 1) return 0L;

    double d = 1 + (8 * triangle);
    if (d > 0) {
        double x1 = (sqrt(d) - 1) / 2;
        double x2 = -(sqrt(d) + 1) / 2;
        double n = 0.0;
        if (x1 >= 0 && modf(x1, &n) == 0.0) return (long) x1;
        if (x2 >= 0 && modf(x2, &n) == 0.0) return (long) x2;
    }

    return 0L;
}

long long getTriang ()
{
    char buff[BUFF_LENGTH];
    int c = 0;
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (count >= MAX_COUNT) return 0L;

        char ch = (char) c;
        if (ch == '\n') break;

        if (isdigit(ch)) {
            buff[count] = ch;
            ++count; /* счетчик */
        } else if (count == 0 && ch == '+') {
            /* do nothing */
            continue;
        } else {
            return 0L;
        }
    }

    buff[count] = '\0';

    // printf("%s - %LLi\n", buff, atoll(buff));
    return atoll(buff);
}