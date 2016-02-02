#include <stdio.h>

// #ifdef _WIN32
//     #define SYSTEM "Windows"
// #endif

// #ifdef linux
    #define SYSTEM "Linux"
// #endif

int main() {
printf("\n Operating System: %s \n", SYSTEM);
return 0;
}