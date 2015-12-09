// Что будет выведено на экран в результате работы следующей программы?

#include <stdio.h>
int main() {
int x = 1;
if(x>0) {
    int x = 2;
    printf("%d ", ++x);
}
printf("%d", x);
return 0;
}

// 3 1