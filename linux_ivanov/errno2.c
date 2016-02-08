#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main (int argc, char ** argv)
{
    int fd, errno_local;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    fd = open (argv[1], O_RDWR, 0600);
    if (fd == -1) {
        fprintf (stderr, "%s\n", strerror (errno));
        return 1;
    }
    close (fd);
    return 0;
}

// $ gcc -o errno2 errno2.c
// $ ./errno2 myfile
// No such file or directory
// $ mkdir myfile
// $ ./errno2 myfile
// Is a directory
// $ rmdir myfile
// $ touch myfile
// $ ./errno2 myfile
// $ chmod 000 myfile
// $ ./errno2 myfile
// Permission denied