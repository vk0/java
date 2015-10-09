// Свяжите следующие классы в иерархию наследования: Character (Персонаж), LongRange (Персонаж дальнего действия), Wizard (Маг), SwordsMan (Мечник), Archer (Лучник).
// Обратите внимание на методы, объявленные в классах — они приведены в качестве описания интерфейса, которым должны обладать классы. Не изменяйте объявлений методов — они даны как подсказка, просто добавьте наследование в определения классов.

#include <string> // std::string

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange : Character
{
    std::string const & name() const;
    unsigned health() const;
    unsigned range() const;
};

struct SwordsMan : Character
{
    std::string const & name() const;
    unsigned health() const;
    unsigned strength() const;
};

struct Wizard : LongRange
{
    std::string const & name() const;
    unsigned health() const;
    unsigned range() const;
    unsigned mana() const;
};

struct Archer : LongRange
{
    std::string const & name() const;
    unsigned health() const;
    unsigned range() const;
    unsigned accuracy() const;
};