#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
   // Числитель и знаменатель
   int numer, denom;
   // Функция сокращения
   void simplify();
public:
   // Конструктор по умолчанию
   Rational();
   // Конструктор из целого числа
   Rational(int number);
   // Конструктор из числителя и знаменателя
   Rational(int n, int d);

   // Отрицание
   Rational operator -() const;
   // Сложение
   Rational operator +(const Rational& r) const;
   Rational& operator +=(const Rational& r);
   // Вычитание
   Rational operator -(const Rational& r) const;
   Rational& operator -=(const Rational& r);
   // Умножение
   Rational operator *(const Rational& r) const;
   Rational& operator *=(const Rational& r);
   // Деление
   Rational operator /(const Rational& r) const;
   Rational& operator /=(const Rational& r);
   // Инкремент
   Rational operator ++(int); // постфикс
   Rational& operator ++(); // префикс

   // Сравнение на равенство
   bool operator ==(const Rational& r) const;
   // Сравнение на неравенство
   bool operator !=(const Rational& r) const;

   // Преобразования
   operator int() const;
   operator double() const;
   // Ввод и вывод
   friend istream& operator >>(istream& in, Rational& r);
   friend ostream& operator <<(ostream& out, const Rational& r);
};

#endif