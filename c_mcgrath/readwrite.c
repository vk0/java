#include <stdio.h>

int main() {
FILE *orig_ptr;
FILE *copy_ptr;
char buffer[1000];
int num;

orig_ptr = fopen("original.txt", "r");
copy_ptr = fopen("copy.txt", "w");

if((orig_ptr != NULL) && (copy_ptr != NULL)) {
    num = fread(buffer, 1, 1000, orig_ptr);
    fwrite(buffer, 1, num, copy_ptr);
    fclose(orig_ptr);
    fclose(copy_ptr);
    printf( "Done: original.txt copied to copy.txt" ) ;
    printf( "\n%d objects copied.\n" , num ) ;
    return 0;
    } else {
        if(orig_ptr == NULL) printf( "Unable to open original.txt\n") ;
        if(copy_ptr == NULL) printf( "Unable to open copy.txt\n" ) ;
        return 1;
    }
}