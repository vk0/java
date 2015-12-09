// Что будет выведено на экран в результате работы следующей программы?

#include <stdio.h>
void print_x();

int main() {
    int i;
    for(i = 0; i<4; i++)
        print_x();
    return 0;
}

void print_x() {
    static int x = 1;
    printf("%d ", x++);
}

//1 2 3 4