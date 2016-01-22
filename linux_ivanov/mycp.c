#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define BUF_SIZE 4096
char buffer [BUF_SIZE];

int main (int argc, char ** argv)
{
int ifd, i;
FILE * outfile;
ssize_t bytes;
if (argc < 3) {
    fprintf (stderr, "Too few arguments\n");
    return 0;
}

ifd = open (argv[1], O_RDONLY);
if (ifd == -1) {
    fprintf (stderr, "Cannot open input file "
        "(%s)\n", argv[1]);
        return 1;
}

outfile = fopen (argv[2], "w");

if (outfile == NULL) {
    fprintf (stderr, "Cannot open output file "
        "(%s)\n", argv[2]);
        return 1;
}

while ((bytes = read (ifd, buffer, BUF_SIZE)) > 0) {
    for (i = 0; i < bytes; i++)
        fputc (buffer[i], outfile);
}
close (ifd);
fclose (outfile);
return 0;
}