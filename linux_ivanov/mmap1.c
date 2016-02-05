#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#define FLENGTH 256
void reverse (char * buf, int size)
{
    int i;
    char ch;
    for (i = 0; i < (size / 2); i++)
    {
        ch = buf[i];
        buf[i] = buf[size - i - 1];
        buf[size - i - 1] = ch;
    }
}
int main (int argc, char ** argv)
{
    int fd;
    char * buf;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    fd = open (argv[1], O_RDWR);
    if (fd == -1) {
        fprintf (stderr, "Cannot open file (%s)\n",
                 argv[1]);
        return 1;
    }
    buf = mmap (0, FLENGTH, PROT_READ | PROT_WRITE,
                MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        fprintf (stderr, "mmap() error\n");
        return 1;
    }
    close (fd);
    reverse (buf, strlen (buf));
    munmap (buf, FLENGTH);
    return 0;
}

// $ gcc -o mmap1 mmap1.c
// $ echo "" > myfile
// $ echo -n LINUX >> myfile
// $ ./mmap1 myfile
// $ cat myfile
// XUNIL