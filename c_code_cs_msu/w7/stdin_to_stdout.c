// Следующий пример копирует стандартный ввод на стандартный вывод.
#include <stdio.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF) putchar(c);
    return 0;
}