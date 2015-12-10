// Задача 5. Дана программа:

// uint32_t *i = 1024;
// i++;

// Чему равно i?
// gcc -fpermissive 1-3-7.cpp

#include <stdio.h>
int main(){
    uint32_t *i = 1024;
    i++;
    printf("%u", i);
    return 0;
}

// 1028