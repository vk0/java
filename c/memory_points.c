#include <stdio.h>

main() {

int a = 6;
float b = 10.11;
char c = 'k';
printf("%d - %p, %.2f - %p, %c - %p\n", a,&a, b,&b, c,&c);

a = 2; b = 50.99; c = 'z';
printf("%d - %p, %.2f - %p, %c - %p\n", a,&a, b,&b, c,&c);

//int a = 8;
printf("%d \n", *&a);

}
