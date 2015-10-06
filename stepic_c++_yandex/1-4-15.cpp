// Дано три числа. Упорядочите их в порядке неубывания.
// Формат входных данных
// Вводятся три числа.
// Формат выходных данных
// Выведите ответ на задачу.
// Sample Input:
// 1
// 2
// 1
// Sample Output:
// 1 1 2

#include <iostream>
using namespace std;

int main() {
int a,b,c,t;
  cin>>a>>b>>c;

  if (a>b) swap(a,b);
  if (a>c) swap(a,c);
  if (b>c) swap(b,c);

  cout<<a<<" "<<b<<" "<<c;
}