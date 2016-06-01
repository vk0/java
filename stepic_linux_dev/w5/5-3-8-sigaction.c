#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signalno, siginfo_t *si, void *unused)
{
    printf("Called with %d\n", signalno);
}

int main()
{
    int c = 0;

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = signal_handler;
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("Hello %d\n", c++);
        usleep(500000);
    }
    return 0;
}