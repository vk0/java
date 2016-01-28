#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main (void)
{
pid_t result = fork();
if (result == -1) {
    fprintf (stderr, "Error\n");
    return 1;
}
if (result == 0)
    printf ("I'm child with PID=%d\n", getpid());
else
    printf ("I'm parent with PID=%d\n", getpid());
return 0;
}