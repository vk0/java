// По данному целому числу N распечатайте все квадраты натуральных чисел, не превосходящие N, в порядке возрастания.
// Формат входных данных
// Вводится натуральное число.
// Формат выходных данных
// Выведите ответ на задачу.
// Sample Input:
// 50
// Sample Output:
// 1 4 9 16 25 36 49

#include <iostream>

using namespace std;

int main() {
  int n,sqrt = 1;
  cin >> n;
  while (n >= sqrt * sqrt) {
    cout << sqrt * sqrt << " ";
    sqrt = sqrt + 1;
  }
  return 0;
}