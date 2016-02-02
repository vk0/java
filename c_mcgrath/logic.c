#include <stdio.h>

int main() {
int yes = 0, no = 1;
printf( "AND (no&&no): %d \n" , no && no ) ;
printf( "AND (yes&&no): %d \n" , yes && no ) ;
printf( "AND (yes&&yes): %d \n" , yes && yes ) ;
printf( "OR (no||no): %d \n" , no || no ) ;
printf( "OR (yes||no): %d \n" , yes || no ) ;
printf( "OR (yes||yes): %d \n" , yes || yes ) ;
printf( "NOT (yes !yes): %d %d\n" , yes , !yes ) ;
printf( "NOT (no !no): %d %d\n" , no , !no ) ;
return 0;
}