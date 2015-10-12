// На прошлом степе вы познакомились с реализацией паттерна посетитель. Теперь пришло время воспользоваться этими знаниями. Ваш класс должен печатать (используя std::cout) текстовое представление арифметического выражения. Т.е. для объекта класса Number он должен напечатать число, которое в нем хранится, а для объекта класса BinaryOperation он должен напечатать левый операнд, затем операцию, а затем правый операнд.

// Учтите, что операции + и - имеют меньший приоритет, чем операции * и /, т. е. возможно вам придется печатать дополнительные круглые скобки, чтобы сохранить правильный порядок операций.

// Классы иерархии Expression и абстрактный класс Visitor приведены в комментарии в шаблоне для удобства.

// При проверке задания лишние пробелы или лишние скобки будут игнорироваться, т.е. вывод "1+2" эквивалентен выводу "( ( 1 )  +   ( 2 ) )", а вот вывод "1 + 2 * 3" не эквивалентен выводу "((1 + 2) * 3)". Вы можете попытаться минимизировать количество скобок в выводе, но это не требуется.

// Перед выполнением задания внимательно прочитайте содержимое предыдущего степа.

// Требования к реализации: при выполнении задания вы можете заводить любые вспомогательные классы или функции, но не нужно реализовывать функцию main или менять реализацию классов иерархии Expression.

/*
struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression();
};

struct Number : Expression
{
    Number(double value);
    double evaluate() const;

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right);
    ~BinaryOperation();
    double evaluate() const;

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
*/

// #include <iostream>

// /* Этот класс вам нужно реализовать */
// struct PrintVisitor : Visitor {
//     void visitNumber(Number const * number)
//     {
//         std::cout << number->get_value();
//     }
//     void visitBinaryOperation(BinaryOperation const * bop)
//     {
//         Expression const * left = bop->get_left();
//         Expression const * right = bop->get_right();
//         std::cout << '(';
//         left->visit(this);
//         std::cout << ' ' << bop->get_op() << ' ';
//         right->visit(this);
//         std::cout << ')';

//     }
// };

#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value) : value(value) {};
    ~Number() {}

    double evaluate() const { return value; }
    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
            : left(left), op(op), right(right) {};

    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() const {
        if (op == '+') {
            return left->evaluate() + right->evaluate();
        } else if (op == '-') {
            return left->evaluate() - right->evaluate();
        } else if (op == '*') {
            return left->evaluate() * right->evaluate();
        } else if (op == '/') {
            return left->evaluate() / right->evaluate();
        }
    }

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

/* Class to implement */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        Expression const * left = bop->get_left();
        Expression const * right = bop->get_right();

        std::cout << '(';
        left->visit(this);
        std::cout << ' ' << bop->get_op() << ' ';
        right->visit(this);
        std::cout << ')';

    }
};

int main() {

    Expression * a = new Number(7);
    Expression * b = new Number(3);

    Expression * bo = new BinaryOperation(a, '+', b);
    Expression * bo1 = new BinaryOperation(bo, '*', a);

    PrintVisitor * print = new PrintVisitor();
    a->visit(print);
    std::cout << '\n';
    bo->visit(print);
    std::cout << '\n';
    bo1->visit(print);
    std::cout << '\n';

    return 0;
}