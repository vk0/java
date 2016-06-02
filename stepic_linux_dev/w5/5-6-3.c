// Подсчет сигналов
// Разработать приложение, умеющее обрабатывать сигналы SIGUSR1 ,SIGUSR2, SIGTERM. После старта Ваше приложение должно по приходу одного из сигналов SIGUSR1,  SIGUSR2 выполнять их суммирование, а после прихода сигнала SIGTERM, требуется вывести в стандартный поток вывода 2 числа, разделенных пробелом, соответствующих количеству обработанных сигналов SIGUSR1, SIGUSR2, и завершить программу. Вывод оканчивается символом конца строки.

// Пример вызова

// ./solution
// 79 38


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток вывода 2 числа, разделенных пробелом (Строка завершается символом конца строки)

// solution.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int sigusr1_count = 0;
int sigusr2_count = 0;

void sig_handler(int signal_number)
{
    if(signal_number==SIGUSR1)
    {
        ++sigusr1_count;
    }
    if(signal_number==SIGUSR2)
    {
        ++sigusr2_count;
    }
    if(signal_number==SIGTERM)
    {
        printf("%d %d\n", sigusr1_count, sigusr2_count);
        exit(0);
    }
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    while (1)
    {
        usleep(500000);
    }
    return 0;
}

// Makefile

all:    exe
exe:    solution.c
    gcc -o solution  solution.c