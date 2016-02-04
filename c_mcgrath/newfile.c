#include <stdio.h>
int main() {

FILE *file_ptr;

file_ptr = fopen("data.txt", "w");

if(file_ptr != NULL) {
    printf("File created\n");
    fclose(file_ptr);
return 0;
} else {
    printf( "Unable to create file\n" ) ; return 1 ;
    }
}