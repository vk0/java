#include <stdio.h>
#include <math.h>
//gcc -o pow_func pow_func.c -lm

#define N 12
main () {
int nums[N] = {7, 3, 9, -5, -3, 2, 1, 0, 16, -4, 2, 0};
int mask = 0, i;
for (i=0; i < N; i++)
if (nums[i] >= 0)
mask = mask | (int)pow(2,N-i-1);
printf("%o\n", mask);
}
