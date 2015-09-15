// Sample Input:
// 5
// 24958
// 48569
// 48564
// 40506
// 59232
// Sample Output:
// 14
// 15
// 15
// 15
// 15

#include <iostream>
#include <math.h>
using namespace std;
int  main ()
{
    int count = 0;
    int k = 0;
    int a;
    double result;
    cout << "";
    cin >> count;
    int numbers[count];
    while ( k < count) {
        cout << "";
        cin >> a;
        result = log2(a);
        numbers[k] = result;
        k = k + 1;
    }
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << endl;
    }
    cout << endl;
    return 0;
}
