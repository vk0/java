#include <signal.h>
#include <stdio.h>
void sig_handler (int snum)
{
    fprintf (stderr, "signal...\n");
}
int main (void)
{
    struct sigaction act;
    sigemptyset (&act.sa_mask);
    act.sa_handler = &sig_handler;
    act.sa_flags = 0;
    if (sigaction (SIGINT, &act, NULL) == -1) {
        fprintf (stderr, "sigaction() error\n");
        return 1;
    }
    while (1);
    return 0;
}