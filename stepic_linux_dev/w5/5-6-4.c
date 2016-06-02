// "Правильный" демон

// В задании требуется доработать демон, разработанный ранее в задании 6 модуля 4.5. Задача -- снабдить демон обработчиком сигнала SIGURG, по приходу которого демон должен завершать свою работу.

// Пример вызова

// ./solution
// 13336


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток PID созданного демона. (Строка завершается символом конца строки)

// solution.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

void sig_handler(int signal_number)
{
    if (signal_number == SIGURG)
    {
        exit(0);
    }
}

int daemonize()
{
    int i;
    // already a daemon
    if (getppid() == 1) {
        return 0;
    }
    i = fork();
    // fork error
    if (i < 0)
    {
        exit(1);
    }
    // parent exits
    if (i > 0) {
        exit(0);
    }

    // child (daemon) continues
    printf ("%d\n", (int) getpid());
    // obtain a new process group
    setsid();
    // close all descriptors
    for (i = getdtablesize(); i >= 0; --i) close(i);

    // sig_handler
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sig_handler;
    sigaction(SIGURG, &sa, NULL);
}

main()
{
    daemonize();
    while (1) {
        sleep(1);
    }
}


// Makefile

all:    exe
exe:    solution.c
    gcc -o solution  solution.c