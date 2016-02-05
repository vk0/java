#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main (int argc, char ** argv)
{
    int fd;
    char ch;
    if (argc < 2) {
        fprintf (stderr, "dst: Too few arguments\n");
        return 1;
    }
    fd = atoi (argv[1]);
    while (read (fd, &ch, 1) > 0)
        write (1, &ch, 1);
    close (fd);
    return 0;
}

// Вот как все это работает:
// $ gcc - o pipe1 - parent pipe1 - parent.c
// $ gcc - o pipe1 - src pipe1 - src.c
// $ gcc - o pipe1 - dst pipe1 - dst.c
// $ . / pipe1 - parent
// Wait please.....
// Hello World