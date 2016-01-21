#include <stdio.h>

int main (int argc, char ** argv)
{
char * value;
if (argc < 2) {
    fprintf (stderr, "Usage: myenv2 <variable>\n");
    return 1;
}
value = (char*) getenv (argv[1]);
if (value == NULL)
    printf ("%s not found\n", argv[1]);
else
    printf ("%s=%s\n", argv[1], value);
    return 0;
}