// Рассмотрим следующий пример: на стандартном потоке ввода задаётся последователь- ность вещественных чисел. Ввод завершается концом файла. Необходимо распечатать на стандартный поток вывода только числа, не превышающие среднего значения всех введён- ных чисел. Для хранения чисел мы будем использовать расширяемый массив.

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int arr_a = 0, arr_u = 0, i;
    double *arr = 0;
    double s = 0, v;
    arr_a = 16;
    if (!(arr = (double*) malloc(arr_a * sizeof(arr[0]))))
        goto out_of_mem;
    while (scanf("%lf", &v) == 1) {
        if (arr_u == arr_a) {
            arr_a *= 2;
            if (!(arr = (double*) realloc(arr, arr_a * sizeof(arr[0]))))
                goto out_of_mem;
        }
        s += v;
        arr[arr_u] = v;
        arr_u++;
    }
    if (!arr_u) return 0;
    s /= arr_u;
    for (i = 0; i < arr_u; i++)
        if (arr[i] <= s) printf("%g\n", arr[i]);
    return 0;
out_of_mem:
    fprintf(stderr, "memory exhausted\n");
    return 1;
}
