// По данной строке определите, является ли она палиндромом (то есть, читается одинаково как слева-направо, так и справа-налево).

// Входные данные

// На вход подается 1 строка без пробелов.

// Выходные данные

// Необходимо вывести yes, если строка является палиндромом, и no в противном случае.

// Sample Input:

// kayak

// Sample Output:

// yes

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int cswitch = 1;
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - (i + 1)]){
            cswitch = 0;
            break;
        }
    }
    if(cswitch == 1){
        cout << "yes";
    }   else    {
        cout << "no";
    };
  return 0;
}