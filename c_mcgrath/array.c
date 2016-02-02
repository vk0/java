#include <stdio.h>

int main() {
int arr[3];
arr[0] = 100;
arr[1] = 200;
arr[2] = 300;

char str[10] = {'C', ' ', 'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};

printf( "1st element value: %d \n" , arr[0] ) ;
printf( "2nd element value: %d \n" , arr[1] ) ;
printf( "3rd element value: %d \n" , arr[2] ) ;
printf( "String: %s \n" , str ) ;

return 0;
}