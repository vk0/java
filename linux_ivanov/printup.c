#include <ctype.h>
#include <stdio.h>
#include <string.h>

void print_up(const char * str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    printf ("%c", toupper(str[i]));
    printf ("\n");
}

int main (int argc, char ** argv)
{
if (argc < 2) {
    fprintf (stderr, "Wrong arguments\n");
    return 1;
}
    print_up(argv[1]);
    return 0;
}