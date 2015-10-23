#ifndef _FIELD_H
#define _FIELD_H

// Поле для игры "4 в ряд"

// Ширина и высота поля
const int FIELD_WIDTH = 7;
const int FIELD_HEIGHT = 6;
// Тип "ячейка поля"
enum Cell
{
   EMPTY,
   RED,
   YELLOW
};
class Field
{
   // Двумерный массив для хранения игрового поля
   Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
   // Очередь хода
   bool isRedTurn;
   // Кто на данный момент выиграл
   Cell winner;

   // Закрытая функция проверки победителя
   void checkWinner();
public:
   // Конструктор, очищает поле
   // isRedFirst - true, если первыми ходят красные
   Field(bool isRedFirst);
   // Очистка поля по требованию
   // isRedFirst - true, 
   // если после очистки первыми ходят красные
   void clear(bool isRedFirst);
   // Очередной ход
   // column - номер колонки хода, от 1 до 7
   // результат - true, если ход успешно сделан,
   // false в обратном случае
   bool makeTurn(int column); 
   // Выиграна ли игра
   // red - true, если вопрос относится к красному игроку
   // результат - true, если игра выиграна данным игроком
   bool isWon(bool red) const;
   // Окончена ли игра
   // Игра окончена, если кто-либо выиграл
   // или если заняты все ячейки
   bool isOver() const;
   // Доступ к ячейкам
   // i номер колонки от 1 до 7
   // j номер строчки от 1 (нижняя) до 6 (верхняя)
   Cell getCell(int i, int j) const;
   // Ходит ли красный игрок
   bool isRedTurnNow() const;
   // Распечатка в консоль
   void print() const;
   // Распечатка результата в консоль
   void printResult() const;
};

#endif