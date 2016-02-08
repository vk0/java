#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main (int argc, char ** argv)
{
    int month;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    month = atoi (argv[1]);
    assert ((month >= 1) && (month <= 12));
    return 0;
}

// $ make FLAGS=-DNDEBUG
// gcc -DNDEBUG -o assert1 assert1.c
// $ ./assert1 15