// Мультиплексированный ввод
// В текущем каталоге есть 2 канала in1 in2, в которые в случайном порядке поступают числа, которые необходимо просуммировать и вывести окончательную сумму на экран. Сумма выводится в отдельной строке, зевершающейся символом конца строки. Признаком окончания подачи символов в каналы является закрытие этих каналов посылающей стороной.

// Подсказка﻿: для неблокирующего чтения использовать select.

// Пример вызова

// ./solution
// 795


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток вывода число (в отдельной строке)

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>

#define FIFO1 "./in1"
#define FIFO2 "./in2"

int main()
{
    char buf1[100];
    char buf2[100];
    int fd1, fd2;
    int sum = 0;
    int nread;

    fd1 = open(FIFO1, O_RDONLY | O_NONBLOCK, 0);
    fd2 = open(FIFO2, O_RDONLY | O_NONBLOCK, 0);

    while (1)
    {
        int fsum = 2;
        fd_set fds;
        int maxfd;
        int res;
        FD_ZERO(&fds);
        FD_SET(fd1, &fds);
        FD_SET(fd2, &fds);
        maxfd = fd1 > fd2 ? fd1 : fd2;
        select(maxfd + 1, &fds, NULL, NULL, NULL);
        memset(buf1, 0, sizeof(buf1));
        if (FD_ISSET(fd1, &fds))
        {
            if (nread = read(fd1, buf1, sizeof(buf1)) > 0)
            {
                sum = sum + atoi(buf1);
            } else {
                fsum--;
            }

        }
        memset(buf2, 0, sizeof(buf2));
        if (FD_ISSET(fd2, &fds))
        {
            if (nread = read(fd2, buf2, sizeof(buf2)) > 0)
            {
                sum = sum + atoi(buf1);
            } else {
                fsum--;
            }
        }
        if (fsum == 0)
            break;
    }
    printf("%d\n", sum);
    return 0;
}