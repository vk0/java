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

#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    int total = 0;
    char buf1[256];
    char buf2[256];

    /* open both pipes */
    if ((fd1 = open("in1", O_RDONLY | O_NONBLOCK)) < 0) {
        perror("open p1");
        return 1;
    }

    if ((fd2 = open("in2", O_RDONLY | O_NONBLOCK)) < 0) {
        perror("open p2");
        return 1;
    }

    while (1) {
        int sum = 2;
        int rc, maxfd;
        fd_set watchset;       /* fds to read from */
        fd_set inset;          /* updated by select() */

        FD_ZERO(&watchset);
        FD_SET(fd1, &watchset);
        FD_SET(fd2, &watchset);

        maxfd = fd1 > fd2 ? fd1 : fd2;
        inset = watchset;

        if (select(maxfd + 1, &inset, NULL, NULL, NULL) < 0) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(fd1, &inset)) {
            rc = read(fd1, buf1, sizeof(buf1));
            total = total + atoi(buf1);
            if (rc < 0) {
                perror("read");
                return 1;
            } else {
                sum--;
            }
        }
        if (FD_ISSET(fd2, &inset)) {
            rc = read(fd2, buf2, sizeof(buf2));
            total = total + atoi(buf1);
            if (rc < 0) {
                perror("read");
                return 1;
            } else {
                sum--;
            }
        }
        if (sum == 0)
            break;
    }
    printf("%d\n", total);
    return 0;
}