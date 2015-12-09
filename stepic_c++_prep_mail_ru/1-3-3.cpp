// Что будет выдано на печать в результате работы следующей программы?

#include <stdio.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"

char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;
int main(){
    printf("%s", **++cpp);
    printf("%s", *--*++cpp+3);
    printf(" %s", *cpp[-2]+3);
    printf("%s", cpp[-1][-1]+1);
    return 0;
}

// POINTER STEW