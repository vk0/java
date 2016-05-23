// You're spending your afternoon at a local school, teaching kids how to code. You give them a simple task: find the difference between the maximum and minimum values in an array of integers.

// After a few hours, they came up with some promising source code. Unfortunately, it doesn't compile! Since you don't want to discourage them, you decide to make their code work without modifying it by adding preprocessor macros.

// Review the locked stub code in your editor and add the preprocessor macros necessary to make the code work.

// Input Format

// The first line contains an integer, , denoting the size of the array.
// The second line contains  space-separated integers, , describing the elements in the array.

// Constraints

// Output Format

// You are not responsible for printing any output to stdout. Once the necessary preprocessor macros are written, the locked code in your editor will print a line that says , where  is the difference between the maximum and minimum values in the array.

// Sample Input

// 5
// 32 332 -23 -154 65
// Sample Output

// Result = 486
// Explanation


#include <limits>
#include <algorithm>    // std::max

#define INF std::numeric_limits<int>::max();
#define io(v) cin>>v
#define toStr(str) #str
#define FUNCTION(func,sign)  void func(int &m, int x){ m=  (((m) sign (x)) ? (m) : (x)); }
#define foreach(v,i) for (int i=0;i<v.size();i++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;

}