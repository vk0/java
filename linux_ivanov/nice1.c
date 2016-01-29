#include <unistd.h>
#include <stdio.h>
int main (void)
{
    int newnice = nice (10);
    printf ("New nice: %d\n", newnice);
    return 0;
}