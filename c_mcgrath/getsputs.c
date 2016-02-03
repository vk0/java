#include <stdio.h>

int main() {
char str[51];
printf( "\nEnter up to 50 characters with spaces:\n" ) ;
gets(str);
printf( "fgets() read: " ) ;
puts(str);
printf( "\nEnter up to 50 characters with spaces:\n" ) ;
scanf("%s", str);
printf( "scanf() read: %s\n" , str ) ;
return 0;
}