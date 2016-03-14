// Что будет передано на стандартный поток вывода в результате выполнения следующего фрагмента кода?

#include <stdio.h>
#include <iostream>

int main( ) {
    int m[] = {1, 2, 3, 4, 5};
    int* p1 = m;
    int* p2 = m;

    p1 += 3;
    ++p2;

    ptrdiff_t dp = p2 - p1;
    int x = *p1;
    int y = *p2;

    std::cout << dp << x << y;
}

//-242