// Программа, корректно ожидающая поступления сигнала SIGINT, приведена ниже.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
volatile int flag;
int cnt;
void sigint_handler(int signo)
{
    flag = 1;
}
int main(void)
{
    sigset_t mask, oldmask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    signal(SIGINT, sigint_handler);
    while (1) {
        sigprocmask(SIG_BLOCK, &mask, &oldmask);
        while (!flag)
            sigsuspend(&oldmask);
        flag = 0;
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
        printf("Ctrl-C pressed\n");
    }
    return 0;
}