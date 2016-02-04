#include <stdio.h>
#include <unistd.h>
int main (int argc, char ** argv)
{
if (argc < 2) {
fprintf (stderr, "Too few arguments\n");
return 1;
}
if (rmdir (argv[1]) == -1) {
fprintf (stderr, "rmdir() error\n");
return 1;
}
return 0;
}