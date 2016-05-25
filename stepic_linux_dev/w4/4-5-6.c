// Разработать программу solution, которая при запуске себя "демонизирует" и остается в  памяти. Перед закрытием стандартного потока вывода stdout унаследованного от родителя, программа должна вывести в него Pid процесса-демона.

// Пример вызова

// ./solution
// 13221


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку перед его закрытием.

// solution.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int daemonize()
{
    int i;
    if (getppid() == 1) return; /* already a daemon */
    i = fork();
    if (i < 0) exit(1); /* fork error */
    if (i > 0) exit(0); /* parent exits */
    /* child (daemon) continues */
    // sprintf(str,"%d\n",getpid());
    printf ("%d\n", (int) getpid ());
    setsid(); /* obtain a new process group */
    for (i = getdtablesize(); i >= 0; --i) close(i); /* close all descriptors */
}

main()
{
    daemonize();
    while (1) sleep(1);
}
