// Дан массив целых чисел в диапазоне [0..10^9]. Размер массива кратен 10 и ограничен сверху значением 2.5 * 10^7 элементов. Все значения массива являются элементами псевдо-рандомной последовательности. Необходимо отсортировать элементы массива за минимально время с использованием быстрой сортировки и вывести каждый десятый элемент отсортированной последовательности.

// Минимальный набор оптимизаций, который необходимо реализовать:

// 1. Оптимизация выбора опорного элемента.

// 2. Оптимизация концевой рекурсии.

// Sample Input:

// 3 0 2 1 5 4 21 4 6 5

// Sample Output:

// 21

#include <stdio.h>
#include <iostream>

inline bool scan_positive_int(long*);
inline void print(long);

template<typename T>
T median(T*, int, int);

template <class T>
void quickSort(T*, int, int);

template <class T>
T partition(T*, int, int);

template <class T>
void insertion_sort(T*, int);

int main() {
    long n = 25000000;

    long* array = new long[n];
    int count = 0;
    while (scan_positive_int(&array[count])) {
        count++;
    }

    //сортируем
    quickSort(array, 0, count - 1);

    //выводим каждый десятый элемент
    for (int i = 9; i < count; i += 10) {
        print(array[i]);
    }

    delete[] array;
    return 0;
}

inline bool scan_positive_int(long *a)
{
    long x = 0;
    register long c = getchar_unlocked();
    if (c == EOF) {
        return false;
    }
    for(; c > 47 && c < 58 ; c = getchar_unlocked()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    *a = x;
    return true;
}

inline void print(long a) {
    int i = 0;
    char S[20];
    while(a > 0) {
        S[i++] = a % 10 + '0';
        a = a / 10;
    }
    --i;
    while(i >= 0) {
        putchar_unlocked(S[i--]);
    }
    putchar_unlocked(' ');
}

template<typename T>
T median(T* array, int left, int right) {
    int mid = (left + right) / 2;
    if (array[mid] < array[left])
        std::swap(array[left], array[mid ]);
    if (array[right] < array[left])
        std::swap(array[left], array[right]);
    if (array[right] < array[mid])
        std::swap(array[mid], array[right]);

    std::swap(array[mid], array[left]);

    return array[left];
}

template <class T>
void quickSort(T *array, int left, int right) {
    while (left < right) {
        if (right - left <= 30) {
            insertion_sort(array + left, right - left + 1);
            break;
        }
        int p = partition(array, left, right);
        if (p - left > right - p) {
            quickSort(array, p + 1, right);
            right = p - 1;
        } else {
            quickSort(array, left, p - 1);
            left = p + 1;
        }
    }
}

template <class T>
T partition(T* array, int left, int right) {
    T pivot = median(array, left, right);
    int i = left + 1;
    int j = right;
    while (true) {
        while (array[i] < pivot && i <= right) i++;
        while (array[j] > pivot) j--;
        if (i >= j) {
            std::swap(array[left], array[i - 1]);
            return i - 1;
        }
        std::swap (array[i], array[j]);
        ++i;
        --j;
    }
}

template <class T>
void insertion_sort(T* array, int size) {
    for(int i = 1; i < size; ++i) {
        //сохраняем значение текущей переменной
        int tmp = array[i];
        //пока предыдущий элемент больше текущего - меняем местами
        for(int j = i; j > 0 && tmp < array[j - 1]; --j) {
            array[j] = array[j - 1];
            array[j - 1] = tmp;
        }
    }
}