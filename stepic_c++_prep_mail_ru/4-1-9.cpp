// Дано определение класса:

// class Test{};


// Отметьте, какие из следующих конструкций корректны.

// Test* var;
// class A {Test* var1, var2;};
// class B {Test& var;};
// const Test test;
// Test var;


#include <iostream>
using namespace std;

class Test{};

int main(){
    Test* var;
    class A {Test* var1, var2;};
    class B {Test& var;};
    const Test test;
    Test var1;
}

//all