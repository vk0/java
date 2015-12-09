// Реализация журналирования

#include <stdio.h>
#define DEBUG 10
#include "debug.h"

int main() {
    int i = 0;
    while(i<6){
        PDEBUG(1,"i=%d",i);
        i++;
    }
}