// Что будет напечатано в результате работы следующей программы?

#include <stdio.h>
void f(int m[5]) {
  for (int i = 0; i<3; i++) {
    m[i] *= 2;
    m++;
  }
}
int main( ){
  int a[5] = {1,1,1,1,1};
  f(a);
  for (int i = 0; i<5; i++)
    printf("%d ", a[i]);
  return 0;
}

//2 1 2 1 2