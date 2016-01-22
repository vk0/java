#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define BUF_SIZE 4096
char buffer[BUF_SIZE+1];

int main (int argc, char ** argv)
{
ssize_t bytes;
int fd;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}

fd = open (argv[1], O_RDONLY);

if (fd == -1) {
    fprintf (stderr, "Cannot open file (%s)\n",argv[1]);
    return 1;
}
while ((bytes = read (fd, buffer, BUF_SIZE)) > 0)
{
    buffer [bytes] = 0;
    printf ("%s", buffer);
}
close (fd);
return 0;
}