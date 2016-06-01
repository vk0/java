#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signalno)
{
    printf("Called with %d\n", signalno);
}

int main()
{
    int c = 0;

    signal(SIGINT, signal_handler);

    while (1)
    {
        printf("Hello %d\n", c++);
        usleep(500000);
    }
    return 0;
}