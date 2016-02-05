#include <stdio.h>
#include <sys/stat.h>
int main (int argc, char ** argv)
{
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    if (mkfifo (argv[1], 0640) == -1) {
        fprintf (stderr, "Can't make fifo\n");
        return 1;
    }
    return 0;
}