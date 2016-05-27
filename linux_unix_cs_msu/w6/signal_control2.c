#include <stdio.h>
#include <signal.h>
int cnt = 0;
volatile int flag = 0;
void sigint_handler(int signo)
{
    flag = 1;
    if (++cnt == 3) {
        signal(SIGINT, SIG_DFL);
        raise(SIGINT);
    }
}
int main(void)
{
    signal(SIGINT, sigint_handler);
    while (1) {
        if (flag) {
            printf("Ctrl-C pressed\n");
            flag = 0;
        } else {
            printf("Some string to print\n");
            sleep(1);
        }
    }
    return 0;
}
