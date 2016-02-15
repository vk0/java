// 1 Write a function that computes the nth Fibonacci number. Your
// function should be called fib and should take as input a single integer value n, and should return an integer value representing the nth Fibonacci number.

// The code example in the notes uses recursion to accomplish this. Write your own function that doesn't use recursion, but uses a loop instead.

// gcc -Wall -o go 5_1_go.c

#include <stdio.h>

int fib(int n);

int main(int argc, char *argv[])
{
    printf("fib(%d)=%d\n", 10, fib(10));
    return 0;
}

int fib(int n)
{
    int i;
    if ((n == 0) | (n == 1)) return n;
    int a = 0;
    int b = 1;
    int tmp;
    for (i = 0; i < n; i++) {
        tmp = b;
        b = a + b;
        a = tmp;
    }
    return a;
}