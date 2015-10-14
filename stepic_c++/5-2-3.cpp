// Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.

// Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.

// Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
#include <iostream>
#include <string>
using namespace std;

struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational & operator +=(Rational const & s) {
        this->add(s);
        return * this;
    }

    Rational & operator -=(Rational const & s) {
        this->sub(s);
        return * this;
    }

    Rational & operator *=(Rational const & s) {
        this->mul(s);
        return * this;
    }

    Rational & operator /=(Rational const & s) {
        this->div(s);
        return * this;
    }

    Rational operator -() {
        Rational tmp(*this);
        tmp.neg();
        return tmp;
    }

    Rational operator +() const {
        return * this;
    }

private:
    int numerator_;
    unsigned denominator_;
};

int main() {
    // Rational r;
    Rational * r = new Rational(121.0,0);
    // r + 5;
    // cout << r << endl;
    // r.foo(97);
}