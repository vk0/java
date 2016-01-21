#include <stdlib.h>
#include <stdio.h>

extern char ** environ;
int main (int argc, char ** argv)
{
int i;
if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
if (unsetenv (argv[1]) != 0) {
    fprintf (stderr, "Cannot unset %s\n", argv[1]);
    return 1;
}
for (i = 0; environ[i] != NULL; i++)
    printf ("%s\n", environ[i]);
    return 0;
}