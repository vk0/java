#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (void)
{
mode_t test_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
printf ("%d\n", test_mode);
return 0;
}