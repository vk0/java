#include <iostream>
#include <locale.h>
using namespace std;
// Функция создает массив из первых
// чисел Фибоначчи
const int FIB_NUMBER=10;
int* createFib(void)
{
   int* arr=new int[FIB_NUMBER];
   arr[0]=arr[1]=1;
   for (int i=2; i<FIB_NUMBER; i++)
      arr[i]=arr[i-1]+arr[i-2];
   // Только тот, кто будет этим массивом 
   // пользоваться, должен в конце освободить память
   return arr;
}

int main(void)
{
   setlocale(LC_ALL, "Russian");
   int* fibArr=createFib();
   cout<<"Числа Фибоначчи: ";
   for (int i=0; i<FIB_NUMBER; i++)
      cout<<fibArr[i]<<" ";
   cout<<endl;
   delete[] fibArr;
   return 0;
}

