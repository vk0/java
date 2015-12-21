// Проверьте, принадлежит ли точка данной закрашенной области:


// Если точка принадлежит области (область включает границы), выведите слово YES, иначе выведите слово NO.
// Решение должно содержать функцию IsPointInArea(x, y), возвращающую True, если точка принадлежит области и False, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInArea и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
// Функция IsPointInArea не должна содержать инструкцию if.

// Формат входных данных
// Вводятся два действительных числа.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input 1:

// -4
// -4

// Sample Output 1:

// NO


// Sample Input 2:

// -4
// -3

// Sample Output 2:

// NO

#include <iostream>
#include <cmath>

using namespace std;

bool isInCircle(int x, int y){
    return sqrt(pow(x + 1, 2) + pow(y - 1, 2)) < 2;
}

bool isOnCircle(int x, int y){
    return sqrt(pow(x + 1, 2) + pow(y - 1, 2)) == 2;
}

bool isInUTr(int x, int y){
    return y >= -x && y >= 2 * x + 2;
}

bool isInLTr(int x, int y){
    return y <= -x && y <= 2 * x + 2;
}

bool isInArea(int x, int y){
    return (isInUTr(x, y) && (isInCircle(x, y) || isOnCircle(x, y))) ||
        (isInLTr(x, y) && (!isInCircle(x, y) || isOnCircle(x, y)));
}

int main(){
    int x, y;
    cin >> x >> y;
    if(isInArea(x, y) == true){
        cout << "YES";
    }   else    {
        cout << "NO";
    }
    return 0;
}