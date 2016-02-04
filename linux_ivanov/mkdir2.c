#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main (int argc, char ** argv)
{
mode_t mode = 0777;
if (argc < 2) {
fprintf (stderr, "Too few arguments\n");
return 1;
}
umask (0000);
if (mkdir (argv[1], mode) == -1) {
fprintf (stderr, "mkdir() error\n");
return 0;
}
return 0;
}