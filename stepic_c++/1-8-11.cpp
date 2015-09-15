#include <iostream>
#include <cmath>
using namespace std;

// Linear equation
// ax2 + bx + c = 0

int  main ()
{
    int a;
    int b;
    int c;
    int roots;
    double x1;
    double x2;
    cout << "";
    cin >> a >> b >> c;
    double discr = b * b - 4 * a * c;
    //cout << discr << endl;
    if ( discr > 0 ) {
        roots = 2;
        x1 = (-b + sqrt(discr)) / (2 * a);
        x2 = (-b - sqrt(discr)) / (2 * a);
        cout << x1 << " " << x2 << endl;
    } else if ( discr == 0 ){
        roots = 1;
        x1 = -b / (2 * a);
        cout << x1 << " " << x1 << endl;
    } else {
        roots = 0;
        cout << "No real roots" << endl;
    }
}