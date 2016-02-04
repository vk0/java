#include <unistd.h>
#include <stdio.h>
int main (int argc, char ** argv)
{
if (argc < 3) {
fprintf (stderr, "Too few arguments\n");
return 1;
}
if (symlink (argv[1], argv[2]) == -1) {
fprintf (stderr, "link() error\n");
return 1;
}
return 0;
}