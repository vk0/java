#include <stdlib.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
char * var;
char initvar[1024];

if (argc < 3) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
sprintf (initvar, "%s=%s", argv[1], argv[2]);
putenv (initvar);
var = getenv (argv[1]);

if (var == NULL)
    printf ("Variable %s doesn't exist\n", argv[1]);
else
    printf ("%s=%s\n", argv[1], var);
    return 0;
}