// Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:
//     GCD(a,b)=GCD(b,a mod b)
//     GCD(0,a)=a
//     GCD(a,b)=GCD(b,a)
// Требования к реализации: в данном задании запрещено пользоваться циклами. Вы можете заводить любые вспомогательные функции, если они вам нужны. Функцию main определять не нужно.

#include <iostream>
#include <cstdio>
using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
    if (a==0)
        return b;
    if(b==0)
        return a;
    if (a == b)
        return b;
    else
        return gcd(b,a%b);
}

int main() {
    cout << "GCD result: "<< gcd(10,5) << endl;
}