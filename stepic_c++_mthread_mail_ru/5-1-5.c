// Сколько раз выведется "Hello!\n"?

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    fork();
    fork();
    fork();
    fork();
    printf("Hello!\n");
    return 0;
}

//16