#include <stdio.h>
#include <unistd.h>
int main (int argc, char ** argv)
{
if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
if (unlink (argv[1]) == -1) {
    fprintf (stderr, "Cannot unlink file "
        "(%s)\n", argv[1]);
    return 1;
}
return 0;
}