// Какое значение примет переменная z после выполнения следующего фрагмента программы?
// int x=1, y=2, z;
// z = x & y | (x && y);

#include <stdio.h>
int main() {
int x=1, y=2, z;
z = x & y | (x && y);
printf("%d", z);
return 0;
}

// 1