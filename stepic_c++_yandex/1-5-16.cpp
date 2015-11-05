// Определите наименьшее расстояние между двумя локальными максимумами последовательности натуральных чисел, завершающейся числом 0. Если в последовательности нет двух локальных максимумов, выведите число 0.

// Начальное и конечное значение при этом локальными максимумами не считаются.

// Формат входных данных
// Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания).
// Формат выходных данных
// Выведите ответ на задачу.
// Sample Input 1:
// 1
// 2
// 1
// 1
// 2
// 1
// 2
// 1
// 0
// Sample Output 1:
// 2

// Sample Input 2:
// 1
// 2
// 3
// 0
// Sample Output 2:
// 0

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int prv, cur, nxt, pos = 0, prv_max = 0, min_len = 0, cur_len;
  int count = 0;
  if (cin>>prv && prv)
  {
    if (cin >> cur && cur)
    {
      if (cin >> nxt)
      {
        pos = 2;
        while (nxt)
        {
          if ((prv < cur) && (cur > nxt))
          {
            if (prv_max != 0 )
            {
              cur_len = pos - prv_max;
              if (min_len == 0)
                min_len = cur_len;
              else
                min_len = min(min_len,cur_len);
            }
            prv_max = pos;
          }
          prv = cur;
          cur = nxt;
          cin >> nxt;
          pos++;

        }
      }
    }
  }
  cout<<min_len;
}