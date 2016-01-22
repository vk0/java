#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main (int argc, char ** argv)
{
int fd;
mode_t fmode = 0755;
if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}

fd = creat (argv[1], fmode);
if (fd == -1) {
    fprintf (stderr,
        "Cannot create file (%s)\n", argv[1]);
        return 1;
}
close (fd);
return 0;
}