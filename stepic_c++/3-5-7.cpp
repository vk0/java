// Задание повышенной сложности.

// Определен следующий класс (он также приведен в комментарии в шаблоне кода):

// struct Cls {
//     Cls(char c, double d, int i);
// private:
//     char c;
//     double d;
//     int i;
// };
// Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, которые дают полный доступ к этим полям (см. шаблон кода), не смотря на то, что они закрытые.

// Внимание: предполагаемое решение этого задания существенно опирается на Undefined Behaviour и является исключительно учебным, но полезно для лучшего понимания того, как работают модификаторы доступа. Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), но мы настоятельно не рекомендуем использовать подобные трюки в боевом коде.

// Требования к реализации: при решении этого задания вам разрешается заводить любые вспомогательные функции и классы, но не изменять определение класса Cls. Не нужно вводить или выводить что-либо, также не нужно определять функцию main.

#include <iostream>
using namespace std;

/*
 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *
 */

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.

char &get_c(Cls &cls) {

    Cls * obj = &cls;
    char * p_obj = (char *) obj;

    char & r_c = * p_obj;
    return r_c;
}

double &get_d(Cls &cls) {

    Cls * obj = &cls;
    double * p_obj = (double *) obj;
    double * p_d = p_obj + 1;

    double & r_d = * p_d;
    return r_d;
}

int &get_i(Cls &cls) {

    Cls * obj = &cls;
    int * p_obj = (int *) obj;
    int * p_i = p_obj + 4;

    int & r_i = * p_i;
    return r_i;
}
