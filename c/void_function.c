#include <stdio.h>
void multi (int *px, int y); //void - значет ничего не возвращает

main () {
    int x = 34, y = 6;
    multi(&x, 367); //первым аргументом передает адрес
    multi(&y, 91);
    printf("%d %d\n", x, y);
}

void multi (int *base, int pow) {
    while (pow >= 10) {
    *base = *base * 10;
    pow = pow / 10;
    }
}
