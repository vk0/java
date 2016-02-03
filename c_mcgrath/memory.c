#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {

int size, *mem;
mem = malloc(100 * sizeof(int));

if (mem != NULL) {
    size = _msize(mem);
    printf( "\nSize of block for 100 ints: %d bytes\n", size ) ;
    printf( "Beginning at %p\n" , mem ) ;
} else {
    printf( "!!! Insufficient memory\n") ; return 1 ;
}

// mem = realloc(mem, size + (100 * sizeof(int)));

// if (mem != NULL) {
//     size = _msize(mem);
//     printf( "\nSize of block for 200 ints: %d bytes\n" , size ) ;
//     printf( "Beginning at %p\n" , mem ) ;
// } else {
//     printf( "!!! Insufficient memory\n") ; return 1 ;
// }

free(mem);
return 0;
}