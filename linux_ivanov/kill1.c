#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char ** argv)
{
    pid_t dpid;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    dpid = atoi (argv[1]);
    if (kill (dpid, SIGKILL) == -1) {
        fprintf (stderr, "Cannot send signal\n");
        return 1;
    }
    return 0;
}