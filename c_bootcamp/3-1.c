// 1 Write a program that converts 27^{°} from degrees Fahrenheit (F) to degrees Celsius (C) using the following formula, and write the result to the screen: C = (F-32)/1.8

// gcc -Wall -o go 3_1.c

#include <stdio.h>

int main(int argc, char **argv)
{
    float degF = 27.0;
    float degC;
    degC = (degF - 32.0) / 1.8;
    printf("%.2f deg Fahrenheit = %.2f deg Celsius\n", degF, degC);
    return 0;
}