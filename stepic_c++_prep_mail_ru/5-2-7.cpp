// Какие из следующих операторов пройдут успешно скомпиллируются?

// string str1 = "abc"; string str2 = str1+str1;
// char *str1 = "abc"; char *str2 = str1+str1;
// string str1 = "abc"; string* str2= &str1;
// string str1 = "abc"; string& str2 = str1; string str3 = str2+str2;


#include <iostream>
using namespace std;


int main () {
    //string str1 = "abc"; string str2 = str1+str1; //+
    //char *str1 = "abc"; char *str2 = str1+str1; //fail
    //string str1 = "abc"; string* str2= &str1; //+
    //string str1 = "abc"; string& str2 = str1; string str3 = str2+str2; //+
    return 0;
}

//1,3,4