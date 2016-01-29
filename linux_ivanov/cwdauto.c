#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PWD_BUF_SIZE 1024

int main (void)
{
char * buf;
if (buf == NULL) {
    fprintf (stderr, "buf is NULL\n");
    return 1;
}

buf = getcwd (NULL, PWD_BUF_SIZE);

if (buf == NULL) {
    fprintf (stderr, "getcwd() error\n");
    return 1;
}

printf ("Current directory: %s\n", buf);
printf ("Basename: %s\n", basename (buf));
free (buf);
return 0;
}