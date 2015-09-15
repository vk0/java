#include <iostream>
using namespace std;
int  main ()
{
    int count = 0;
    int k = 0;
    int a;
    int b;
    int sum;
    cout << "";
    cin >> count;
    int numbers[count];
    while ( k < count) {
        cout << "";
        cin >> a >> b;
        sum = (a + b);
        numbers[k] = sum;
        //cout << (a + b);
        k = k + 1;
    }
    for (int i = 0; i < count; i++)
    {
        cout << numbers[i] << endl;
    }
    cout << endl;
    return 0;
}
