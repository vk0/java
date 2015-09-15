// Sample Input:
//     There are    a     lot  of    spaces  here
// Sample Output:
//     There are a lot of spaces here
#include <iostream>
using namespace std;
int main()
{
    char c = '\0';
    char sp;
    char last;
    while (cin.get(c)) {
        sp = c;
        if (sp != ' ') {
            cout << sp;
            last = sp;
        } else if ( sp == ' ' && sp != last ) {
            cout << sp;
            last = sp;
        }
    }
    return 0;
}