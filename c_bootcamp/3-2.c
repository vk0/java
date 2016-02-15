// 2 Write a program that computes the (two) roots of the quadratic equation: ax^2+bx+c=0
// where a=1.2a=1.2, b=2.3b=2.3 and c=−3.4c=−3.4.
// You can hard-code values of aa, bb and cc and then compute and print the two solutions for xx, to 5 decimal places. You can use http://www.wolframalpha.com/input/?i=1.2*x*x+%2B++2.3*x+++-3.4+%3D+0 to check your arithmetic.

// gcc -Wall -o go 3_2.c -lm

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    double a, b, c, x1, x2;
    a = 1.2;
    b = 2.3;
    c = -3.4;
    x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    printf("%.2f x^2 + %.2f x + %.2f = 0\n", a, b, c);
    printf("x = %.5f and %.5f\n", x1, x2);
    return 0;
}