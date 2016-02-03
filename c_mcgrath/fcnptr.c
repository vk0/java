#include <stdio.h>

int bounce(int a);
int caller((int(*function) (int)), int b);

int main() {
int num;
int (*fptr)(int) = bounce;
num = (*fptr)(10);
printf( "Returned Value: %d\n" , num ) ;
num = caller(fptr, 5);
printf( "Returned Value: %d\n", num ) ;
return 0;
}

int bounce(int a) {
    printf( "\nReceived Value: %d\n", a ) ;
    return((3 * a) + 3);
}

int caller(int (*function)(int), int b) {
    (function*)(b);
}