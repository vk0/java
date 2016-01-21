#include <stdio.h>
#include <unistd.h>

extern char ** environ;
int main (void)
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf ("%s\n", environ[i]);
        return 0;
}