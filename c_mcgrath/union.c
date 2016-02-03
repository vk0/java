#include <stdio.h>

typedef struct { int num; char ltr,*str;} Distinct;
typedef union { int num; char ltr, *str;} Unified;

int main() {
Distinct sdata = {10, 'C', "Program"};
Unified udata;

printf( "\nStructure:\nNumber: %d", sdata.num ) ;
printf( "\tStored at: %p\n" , &sdata.num ) ;
printf( "Letter: %c" , sdata.ltr ) ;
printf( "\tStored at: %p\n" , &sdata.ltr ) ;
printf( "String: %s" , sdata.str ) ;
printf( "\tStored at: %p\n" , &sdata.str ) ;

udata.num = 16;

printf( "\nUnion:\nNumber: %d" , udata.num ) ;
printf( "\tStored at: %p\n" , &udata.num ) ;

udata.ltr = 'A';
printf( "Letter: %c" , udata.ltr ) ;
printf( "\tStored at: %p\n" , &udata.ltr ) ;

udata.str = "Union" ;
printf( "String: %s", udata.str ) ;
printf( "\tStored at: %p\n" , &udata.str ) ;

return 0;
}