#include <stdio.h>
#include <sys/stat.h>
int main (int argc, char ** argv)
{
if (argc < 2) {
fprintf (stderr, "Too few arguments\n");
return 1;
}
if (mkdir (argv[1], 0755) == -1) {
fprintf (stderr, "mkdir() error\n");
return 0;
}
return 0;
}