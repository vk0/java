#include <stdio.h>

int main() {
enum SNOOKER {RED=1,YELLOW, GREEN, BROWN, BLUE, PINK, BLACK};
enum SNOOKER pair = RED + BLACK; //1 + 7
printf( "Pair value: %d \n" , pair ) ;

typedef unsigned short int USINT;

USINT num = 16;
printf( "Unsigned short int value: %d \n" , num ) ;

return 0;
}