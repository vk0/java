#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define HELLO_MSG "Hello World\n"
int main (int argc, char ** argv)
{
    int fd;
    if (argc < 3) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    fd = open (argv[1], O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        fprintf (stderr, "Cannot open file "
                 "(%s)\n", argv[1]);
        return 1;
    }
    if (rename (argv[1], argv[2]) == -1) {
        fprintf (stderr, "rename() error\n");
        return 1;
    }
    if (write (fd, HELLO_MSG,
               strlen (HELLO_MSG)) == -1) {
        fprintf (stderr, "write() error\n");
        return 1;
    }
    close (fd);
    return 0;
}