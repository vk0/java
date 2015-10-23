#include "Field.h"
#include <iostream>
#include <locale.h>

using namespace std;

// Тестируем игровое поле
// Каждая строчка массива обозначает ходы партии
// 0 в начале строчки - последний элемент
// Ходы от 1 до 7
// Строчка заканчивается отрицательным числом,
// обозначающим итог
// -1 партия не закончена
// -2 победа красного
// -3 победа желтого
// -4 ничья
int turns[] = 
{
   4, 4, 4, -1,
   4, 3, 5, 2, 6, 1, 7, -2,
   4, 3, 4, 3, 4, 3, 5, 3, -3,
   1, 2, 2, 3, 4, 3, 3, 4, 5, 4, 4, -2,
   1, 2, 1, 2, 1, 2, 3, 4, 3, 4, 3, 4, 5, 6, 5, 6, 5, 6,
   2, 1, 2, 1, 2, 1, 4, 3, 4, 3, 4, 3, 6, 5, 6, 5, 6, 5, 
   7, 7, 7, 7, 7, 7, -4,
   0
};

bool test(void)
{
   int i=0;
   // Цикл по партиям
   int game=1;
   int turn=1;
   Field field(true);
   while (turns[i] != 0)
   {
      while (turns[i] > 0)
      {
         if (!field.makeTurn(turns[i]))
         {
            cout<<"Провал теста: ход невозможен"<<endl;
            cout<<"Партия "<<game<<" ход "<<turn<<endl;
            return false;
         }
         i++;
         turn++;
      }
      cout<<"Тестовая партия "<<game<<" сыграна"<<endl;
      field.printResult();
      switch (turns[i])
      {
      case -1:
         if (field.isOver())
         {
            cout<<"Провал теста: ожидали незаконченную партию"<<endl;
            field.print();
            return false;
         }
         break;
      case -2:
         if (!field.isWon(true))
         {
            cout<<"Провал теста: ожидали победу красного"<<endl;
            field.print();
            return false;
         }
         break;
      case -3:
         if (!field.isWon(false))
         {
            cout<<"Провал теста: ожидали победу желтого"<<endl;
            field.print();
            return false;
         }
         break;
      case -4:
         if (field.isWon(true) || field.isWon(false) || !field.isOver())
         {
            cout<<"Провал теста: ожидали ничью"<<endl;
            field.print();
            return false;
         }
         break;
      }
      i++;
      game++;
      turn = 1;
      field.clear(true);
   }
   cout<<"Всего сыграно "<<game-1<<" тестовых партий"<<endl;
   return true;
}


int main(void)
{
   setlocale(LC_ALL, "Russian");
   if (!test())
      return -1;
   Field field(true);
   while (!field.isOver())
   {
      field.print();
      cout<<"Ходит "<<
         (field.isRedTurnNow() ? "красный" : "желтый")<<
         " игрок, введите ход (1-7)"<<endl;
      int column;
      cin>>column;
      field.makeTurn(column);
   }
   field.printResult();
   return 0;
}