// Следующий пример блокирует сигнал SIGINT на время выполнения функции printf.

#include <stdio.h>
#include <signal.h>
int cnt = 0;
void sigint_handler(int signo)
{
    printf("Ctrl-C pressed\n");
    if (++cnt == 3) {
        signal(SIGINT, SIG_DFL);
        raise(SIGINT);
    }
}
int main(void)
{
    sigset_t blockset;
    sigemptyset(&blockset);
    sigaddset(&blockset, SIGINT);
    signal(SIGINT, sigint_handler);
    while (1) {
        sigprocmask(SIG_BLOCK, &blockset, 0);
        printf("Some string to print\n");
        sigprocmask(SIG_UNBLOCK, &blockset, 0);
    }
    return 0;
}
