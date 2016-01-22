#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main (int argc, char ** argv)
{
int fd;
char ch;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}

fd = open (argv[1], O_RDONLY);

if (fd == -1) {
    fprintf (stderr, "Cannot open file (%s)\n",argv[1]);
    return 1;
}
while (read (fd, &ch, 1) > 0) printf ("%c", ch);
    if (close (fd) == -1) {
        fprintf (stderr, "Cannot close file "
            "with descriptor=%d\n", fd);
            return 1;
    }
    return 0;
}