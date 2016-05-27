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
    signal(SIGINT, sigint_handler);
    while (1) {
        if (!flag) pause();
        flag = 0;
        printf("Ctrl-C pressed\n");
    }
    return 0;
}