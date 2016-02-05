#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define FIFO_NAME "myfifo"
int main (int argc, char ** argv)
{
    int fifo;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    fifo = open (FIFO_NAME, O_WRONLY);
    if (fifo == -1) {
        fprintf (stderr, "Cannot open fifo\n");
        return 1;
    }
    if (write (fifo, argv[1], strlen (argv[1])) == -1) {
        fprintf (stderr, "write() error\n");
        return 1;
    }
    close (fifo);
    return 0;
}