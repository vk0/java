#include <stdlib.h>
#include <stdio.h>
int main (int argc, char ** argv)
{
int ov_flag = 1;
char * var;
if (argc < 3) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
setenv (argv[1], argv[2], ov_flag);
var = getenv (argv[1]);
if (var == NULL)
    printf ("Variable %s doesn't exist\n", argv[1]);
else
    printf ("%s=%s\n", argv[1], var);
    return 0;
}