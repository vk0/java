#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;
int main(void)
{
   setlocale(LC_ALL, "Russian");
   // Открытие входного файла in.txt
   ifstream in("in.txt");
   if (!in.is_open()) // Успешно ли открытие
   {
      cout<<"Ошибка: файл in.txt не существует"<<endl;
      return -1;
   }
   int a, b, c;
   // Ввод трех целых чисел из файла
   in>>a>>b>>c;
   if (in.fail()) // Не произошла ли ошибка
   {
      cout<<"Ошибка: числа не прочитаны"<<endl;
      return -2;
   }
   cout<<"Прочитаны числа: "<<a<<", "<<b<<", "<<c<<endl;
   // Открытие выходного файла out.txt
   ofstream out("out.txt");
   if (!out.is_open())
   {
      cout<<"Ошибка: не удается записать файл out.txt"<<endl;
      return -3;
   }
   // Вывод a+b+c=sum
   out<<a<<"+"<<b<<"+"<<c<<"="<<a+b+c<<endl;
   cout<<"Программа успешно завершена!"<<endl;
   return 0;
}
   
