#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

#define PWD_BUF_SIZE 1024
#define FILE_BUF_SIZE 4096

char file_buf [FILE_BUF_SIZE];

int main (void)
{
    int fd;
    ssize_t count;
    char * buf = getcwd (NULL, PWD_BUF_SIZE);

    if (buf == NULL) {
        fprintf (stderr, "getcwd() error\n");
        return 1;
    }
    printf ("Old dir: %s\n", buf);
// free(buf);

    if (chdir ("/etc") == -1) {
        fprintf (stderr, "chdir() error\n");
        return 1;
    }
    buf = getcwd (NULL, PWD_BUF_SIZE);

    if (buf == NULL) {
        fprintf (stderr, "getcwd() error\n");
        return 1;
    }
    printf ("New dir: %s\n", buf);
// free(buf);

    fd = open ("fstab", O_RDONLY);

    if (fd == -1) {
        fprintf (stderr, "Cannot open fstab\n");
        return 1;
    }
    printf ("FSTAB:\n");
    while ((count = read (fd, file_buf, FILE_BUF_SIZE)) > 0)
        write (1, file_buf, count);
    close (fd);
    return 0;
}