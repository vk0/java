// 3 Write a program that displays a triangle with height nn and width 2n−12n−1. The output for n=6n=6 would be:
//      *
//     ***
//    *****
//   *******
//  *********
// ***********

// gcc -Wall -o go 4_3.c

#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 6;
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j < (n - i); j++) { printf(" "); }
        for (j = (n - i); j < (n - i) + ((2 * i) - 1); j++) { printf("*"); }
        printf("\n");
    }
    return 0;
}