#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PP_MESSAGE "Hello World\n"
#define WAIT_SECS 5
int main (int argc, char ** argv)
{
    int i, fd;
    if (argc < 2) {
        fprintf (stderr, "src: Too few arguments\n");
        return 1;
    }
    fd = atoi (argv[1]);
    fprintf (stderr, "Wait please");
    for (i = 0; i < WAIT_SECS; i++, sleep (1))
        fprintf (stderr, ".");
    fprintf (stderr, "\n");
    if (write (fd, PP_MESSAGE,
               strlen (PP_MESSAGE)) == -1) {
        fprintf (stderr, "src: write() error\n");
        return 1;
    }
    close (fd);
    return 0;
}