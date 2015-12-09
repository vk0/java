// Что будет выведено на экран в результате работы следующей программы?

#include <stdio.h>
#define SUM(a,b) a+b
#define Print(x) printf("%d ", x)

int main() {
int a = 2, b = 3, c = 5;
Print(SUM(a,b)); //3 + 2
Print(SUM(a,b)*c); //3*5 + 2
Print(c*SUM(a,b)); // 5*2 + 3
return 0;
}

// 5 17 13