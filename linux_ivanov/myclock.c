#include <stdio.h>
#include <time.h>
int main (void)
{
    time_t nt = time (NULL);
    printf ("%s", ctime (&nt));
    return 0;
}