#include <stdio.h>

int main() {
int i;
int nums[5] = {1, 2, 3, 4, 5};
int *ptr0 = &nums[0];
int *ptr1 = &nums[1];
int *ptr2 = &nums[2];
int *ptr3 = &nums[3];
int *ptr4 = &nums[4];

int *ptrs[5] = {ptr0, ptr1, ptr2, ptr3, ptr4};

char str[9] = { 'C', ' ', 'i', 's', ' ', 'F', 'u', 'n', '\0' } ;
char *string = str ;
char *strings[3] = { "Alpha", "Bravo", "Charlie" } ;

for(i = 0; i < 5; i++) {
    printf( "The value at %p is: %d\n" , ptrs[i], *ptrs[i] ) ;
}

printf( "\nString is: %s\n\n" , string ) ;

for(i = 0; i < 3; i++) {
    printf( "String %d is: %s\n" , i , strings[i] ) ;
}
return 0;
}