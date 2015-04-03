#include <stdio.h>

float median (int a, int b); // объявление функции

main () {
    int num1 = 18, num2 = 35;
    float result;

    printf("%10.1f\n", median(num1, num2));
    result = median(121, 346);
    printf("%10.1f\n", result);
    printf("%10.1f\n", median(1032, 1896));
}

float median (int n1, int n2) { // определение функции
    float m;
    m = (float) (n1 + n2) / 2;
    return m;

}
