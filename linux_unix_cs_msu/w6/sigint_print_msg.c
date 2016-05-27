// Рассмотрим программу, которая при поступлении сигнала SIGINT печатает сообщение. Возможный вариант этой программы представлен ниже:

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sigint_handler(int signo)
{
}
int main(void)
{
    signal(SIGINT, sigint_handler);
    while (1) {
        pause();
        printf("Ctrl-C pressed\n");
    }
    return 0;
}