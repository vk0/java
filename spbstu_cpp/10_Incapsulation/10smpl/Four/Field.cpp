#include "Field.h"
#include <iostream>

using namespace std;

Field::Field(bool isRedFirst)
{
   clear(isRedFirst);
}

void Field::clear(bool isRedFirst)
{
   isRedTurn = isRedFirst;
   winner = EMPTY;
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++)
         cells[i][j] = EMPTY;
}

bool Field::makeTurn(int column)
{
   // Если кто-то уже выиграл, ход невозможен
   if (winner != EMPTY)
      return false;
   // Проверка номера колонки на корректность
   if (column < 1 || column > FIELD_WIDTH)
      return false;
   int i=column-1;
   for (int j=0; j<FIELD_HEIGHT; j++)
      // Ищем первую свободную ячейку
      if (cells[i][j]==EMPTY)
      {
         cells[i][j] = isRedTurn ? RED : YELLOW;
         // Проверяем, не выиграл ли кто
         checkWinner();
         isRedTurn = !isRedTurn;
         return true;
      }
   return false;
}

const int DIR_NUMBER = 4;

const int di[] = { 1, 0, 1, 1 };

const int dj[] = { 0, 1, -1, 1 };

const int WIN_LENGTH = 4;

void Field::checkWinner()
{
   // Перебор всех ячеек, откуда четверка начинается
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++)
      {
         Cell start = cells[i][j];
         // Четверка не может начинаться
         // из пустой ячейки
         if (start==EMPTY)
            continue;
         for (int dir=0; dir<DIR_NUMBER; dir++)
         {
            // Текущая длина линии
            int length=0;
            // Текущая ячейка линии
            int iline = i, jline = j;  
            while (++length < WIN_LENGTH)
            {
               iline += di[dir];
               jline += dj[dir];
               // Вышли за пределы
               if (iline < 0 || iline >= FIELD_WIDTH ||
                   jline < 0 || jline >= FIELD_HEIGHT)
                  break;
               // Другой цвет
               if (cells[iline][jline]!=start)
                  break;
            }
            if (length==WIN_LENGTH)
            {
               winner = start;
               return;
            }
         }
      }
}

bool Field::isWon(bool red) const
{
   return red ? (winner==RED) : (winner==YELLOW);
}

bool Field::isOver() const
{
   if (winner != EMPTY)
      return true;
   for (int i=0; i<FIELD_WIDTH; i++)
      for (int j=0; j<FIELD_HEIGHT; j++)
         // Если хоть одна ячейка свободна,
         // игра не окончена
         if (cells[i][j]==EMPTY)
            return false;
   // Все ячейки заняты
   return true;
}

Cell Field::getCell(int i, int j) const
{
   if (i<=0 || i>FIELD_WIDTH ||
       j<=0 || j>FIELD_HEIGHT)
       return EMPTY;
   return cells[i-1][j-1];
}

bool Field::isRedTurnNow() const
{
   return isRedTurn;
}

char sym[] = { '.', 'R', 'Y' };

void Field::print() const
{
   cout<<"1-2-3-4-5-6-7-"<<endl;
   for (int j=FIELD_HEIGHT-1; j>=0; j--)
   {
      for (int i=0; i<FIELD_WIDTH; i++)
      {
         cout<<sym[cells[i][j]]<<" ";
      }
      cout<<endl;
   }
   cout<<"1-2-3-4-5-6-7-"<<endl;
}

void Field::printResult() const
{
   if (isWon(true))
   {
      cout<<"Победил красный игрок"<<endl;
   }
   else if (isWon(false))
   {
      cout<<"Победил желтый игрок"<<endl;
   }
   else if (isOver())
   {
      cout<<"Ничья"<<endl;
   }
   else
   {
      cout<<"Партия не закончена"<<endl;
   }
}
