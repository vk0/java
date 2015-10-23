#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;
int main(void)
{
   setlocale(LC_ALL, "Russian");
   int m, n;
   ifstream in("in.txt");
   if (!in.is_open())
   {
      cout<<"Файл in.txt не существует"<<endl;
      return -1;
   }
   in>>m>>n;
   if (in.fail() || m<1 || n<1)
   {
      cout<<"Некорректные размерности"<<endl;
      return -2;
   }
   double** matrix = new double*[m];
   for (int i=0; i<m; i++)
      matrix[i] = new double[n];
   for (int i=0; i<m; i++)
      for (int j=0; j<n; j++)
         in>>matrix[i][j];
   if (in.fail())
   {
      cout<<"Не удалось прочитать матрицу"<<endl;
      return -3;
   }
   ofstream out("out.txt");
   if (!out.is_open())
   {
      cout<<"Не удалось создать файл out.txt"<<endl;
      return -4;
   }
   for (int j=0; j<n; j++)
   {
      for (int i=0; i<m; i++)
         out<<matrix[i][j]<<" ";
      out<<endl;
   }
   // Освобождаем в обратном порядке
   for (int i=0; i<m; i++)
      delete[] matrix[i];
   delete[] matrix;
   cout<<"Программа завершена успешно"<<endl;
   return 0;
}

