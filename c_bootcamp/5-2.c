// 2 Write a function that determines whether an integer is prime. The
// function should take as input a single integer, and return a 1 if the input is prime, and a 0 if it is not.

// gcc -Wall -o go 5_2.c

#include <stdio.h>

int isprime(int n);

int main(int argc, char *argv[])
{
    printf("isprime(%d)=%d\n", 12, isprime(12));
    printf("isprime(%d)=%d\n", 17, isprime(17));
    return 0;
}

int isprime(int n)
{
    if (n <= 1) return 0;
    int i;
    for (i = 2; (i * i) <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}