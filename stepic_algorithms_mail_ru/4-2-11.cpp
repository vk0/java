// Дан массив неотрицательных целых 64-разрядных чисел. Количество чисел не больше 10^6. Отсортируйте массив методом поразрядной сортировки LSD по байтам.

// Sample Input:

// 3
// 4 1000000 7

// Sample Output:

// 4 7 1000000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int digit(long long int n, int p) {  // Получение p-го байта
    return (n >> (8 * p) & 255);
}

// Сортировка подсчётом массива a по p байту
void counting_sort (long long int *a, int number, const int p) {
    // Максимальное число байтов в числе
    long long int* b = new long long int[number];
    // У байта максимум 256 значений
    long long int c[256] = {0};
    // Подсчитываем количество элементов
    // в массиве соответствующий каждому
    // байту (из сортировок подсчетом)
    for ( int j = 0; j < number; ++j ) {
        c[digit(a[j],p)]++;
    }
    // Модифицируем массив с.
    // c[i] - номер элемента, следующего после i-го блока
    for ( int j = 1; j < 256; ++j ) {
        c[j] += c[j - 1];
    }
    // Cдвигаем массив
    for ( int j = number - 1; j >= 0; --j ) {
        b[--c[digit(a[j],p)]] = a[j];
    }
    for ( int j = 0; j < number; ++j ) {
        a[j] = b[j];
    }
    delete[] b;
}

// Сортировка массива a методом поразрядной сортировки LSD по байтам
long long int* LSD_Sort(long long int *a, int number) {
    long long int max_size = sizeof(long long int);
    // Цикл по всем байтам
    for ( int i = 0; i < max_size; ++i ) {
        counting_sort(a, number, i);
    }
    return a;
}

int main() {
    int number;  // Размер массива
    cin >> number;
    long long int* a = new long long int[number];
    // Заполняем c клавиатуры массив a
    for ( int i = 0; i < number; ++i ) {
        cin >> a[i];
    }
    a = LSD_Sort(a, number);  // Сортируем массив
    for ( int i = 0; i < number; ++i ) {  // Выводим отсортированный массив на экран
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;  // Успех!
}