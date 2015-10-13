// Помните иерархию Expression, которую мы разрабатывали на четвёртой неделе? Реализуйте ScopedPtr, который будет работать с указателями на базовый класс Expression. В этом задании вам требуется реализовать методы get, release и reset, операторы * и -> так, как это было описано в предыдущем степе. А также реализуйте конструктор ScopedPtr от указателя на Expression.

// Подсказка: в качестве признака того, что ScopedPtr не хранит никакого указателя (после вызова release), используйте нулевой указатель, при этом вы можете явно проверить указатель в деструкторе, но делать это не обязательно, так как delete от нулевого указателя ничего не делает.

// Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.

struct Expression;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct ScopedPtr {
    // реализуйте следующие методы:
    //
    // explicit ScopedPtr(Expression *ptr = 0)
    // ~ScopedPtr()
    // Expression* get() const
    // Expression* release()
    // void reset(Expression *ptr = 0)
    // Expression& operator*() const
    // Expression* operator->() const

    explicit ScopedPtr(Expression *ptr = 0): ptr_(ptr) {}
    Expression* get() const {
        return ptr_;
    }
    Expression* release() {
        Expression * temp = ptr_;
        ptr_ = 0;
        return temp;
    }
    void reset(Expression *ptr = 0){
        delete ptr_;
        ptr_ = ptr;
    }
    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }

    ~ScopedPtr(){
        delete ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};