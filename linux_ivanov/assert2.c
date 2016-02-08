#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define FAIL_SUM 10
int myfunc (int a, int b)
{
    printf ("Hello\n");
    return (a + b);
}
int main (int argc, char ** argv)
{
    int a, b;
    if (argc < 3) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    a = atoi (argv[1]);
    b = atoi (argv[2]);
    assert (myfunc (a, b) != FAIL_SUM);
    return 0;
}