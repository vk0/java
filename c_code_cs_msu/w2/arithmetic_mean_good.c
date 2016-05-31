// Рассмотрим пример — вычисление среднего арифметического вводимых чисел.

#include <stdio.h>
enum { MAX_N = 1000000 };
int main(void)
{
    double s = 0;
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "cannot read n\n");
        return 1;
    }
    if (n <= 0 || n >= MAX_N) {
        fprintf(stderr, "invalid value of n: %d\n", n);
        return 1;
    }

    double x[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &x[i]) != 1) {
            fprintf(stderr, "cannot read x[%d]\n", i);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        s += x[i];
    }
    s /= n;
    printf("%.10g\n", s);
    return 0;
}
