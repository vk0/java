// Рассмотрим следующую задачу: удалить из входного потока все пробельные литеры.
#include <stdio.h>
int main()
{
    char c;
    while (scanf("%c", &c) == 1) {
        if (c != ' ') printf("%c", c);
    }
    return 0;
}