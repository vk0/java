// Реализуйте функцию array_size, которая возвращает размер массива, переданного в качестве параметра. Функция должна работать только для массивов! Т. е. если функции передать указатель, должна произойти ошибка компиляции. Примеры:

// int ints[] = {1, 2, 3, 4};
// int *iptr = ints;
// double doubles[] = {3.14};
// array_size(ints); // вернет 4
// array_size(doubles); // вернет 1
// array_size(iptr); // тут должна произойти ошибка компиляции
// Hint: в одной из первых недель мы вам показывали трюк с передачей массивов только заданного размера в функцию (передача массива по ссылке), совместите его с вашими знаниями о шаблонах.

// Sample Input:
// There are no tests for this task
// Sample Output:
// OK

#include <cstddef> // size_t

template <typename T, size_t n>
size_t array_size(const T (&a)[n]) {
    return n;
}

void main() {
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    size_t a1 = array_size(ints); // вернет 4
    size_t a2 = array_size(doubles); // вернет 1
    int ints2[1] = {};
    size_t a3 = array_size(iptr);
}