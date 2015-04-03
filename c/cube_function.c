#include <stdio.h>

int cube (int a); // объявление функции

main () {
    int num1 = 3;

    printf("%10.1d\n", cube(num1));
    printf("%10.1d\n", cube(4));
}

int cube (int n1) { // определение функции
    int m;
    m = (int) (n1 * n1 * n1);
    return m;

}
