#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
int main (int argc, char ** argv)
{
    int fd, errno_local;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    fd = open (argv[1], O_RDWR, 0600);
    if (fd == -1) {
        errno_local = errno;
        switch (errno_local)
        {
        case (ENOENT):
            printf ("not exist\n");
            return 1;
        case (EISDIR):
            printf ("is a directory\n");
            return 1;
        case (EACCES):
            printf ("access denied\n");
            return 1;
        default:
            printf ("unknown error\n");
            return 1;
        }
    }
    close (fd);
    return 0;
}