// if and else are two of the most heavily used conditionals in C/C++. They are used to execute zero or one statement among many statements.

// They can be used in the following three ways.

// if: It is used to execute a statement, given the condition is true.

// if(condition) {
//     ...
// }
// if - else: It is used to execute exactly one of the two statements.

// if(first condition) {
//     ...
// }
// else {
//     ...
// }
// if - else if - else: It is used to execute one of the multiple statements.

// if(first condition) {
//     ...
// }
// else if(second condition) {
//     ...
// }
// .
// .
// .
// else if((n-1)'th condition) {

// }
// else {
//     ...
// }
// You are given a positive integer, ,:

// If , then print the English representation of it. That is "one" for 1, "two" for 2, and so on.
// Otherwise print "Greater than 9" (without quotes).
// Input Format

// Input will contain only one integer, .

// Output Format

// Print the output as described above.

// Sample Input

// 5
// Sample Output

// five
// Sample Input #01

// 8
// Sample Output #01

// eight
// Sample Input #02

// 44
// Sample Output #02

// Greater than 9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int in;
    string num[10] = {"Greater than 9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> in;
    if (in > 9) {
        cout << num[0];
    }
    else {
        cout << num[in];
    }
    return 0;
}