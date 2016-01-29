#include <sys/statvfs.h>
#include <fcntl.h>
#include <stdio.h>
int main (int argc, char ** argv)
{
struct statvfs fs;
int fd;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}

fd = open (argv[1], O_RDONLY);

if (fd == -1) {
    fprintf (stderr, "Cannot open file (%s)\n", argv[1]);
    return 1;
}
if (fstatvfs (fd, &fs) == -1) {
    fprintf (stderr, "fstatvfs() error\n");
    return 1;
}
printf ("Block size: %ld\n", (unsigned long int) fs.f_bsize);
printf ("Blocks: %ld\n", (unsigned long int) fs.f_blocks);
printf ("Blocks free: %ld\n", (unsigned long int) fs.f_bfree);
printf ("Blocks available: %ld\n", (unsigned long int) fs.f_bavail);
printf ("Max. filename length: %ld\n", (unsigned long int) fs.f_namemax);
close (fd);
return 0;
}