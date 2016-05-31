// Рассмотрим пример — вычисление среднего арифметического вводимых чисел.

#include <stdio.h>
int main(void)
{
    double x[10];
    double s = 0;
    int i;
    int n;

    scanf("%d", &n);
    i = 0;
    while (i < n) {
        scanf("%lf", &x[i]);
        i = i + 1;
    }

    i = 0;
    while (i < n) {
        s = s + x[i];
        i = i + 1;
    }
    s = s / n;
    printf("%.10g\n", s);
    return 0;
}