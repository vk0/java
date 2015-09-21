// Реализуйте метод, возвращающий результат следующего логического выражения:
// (c AND secretFunction()) OR (a XOR b)
// secretFunction() – функция, которая возвращает некоторое логическое значение и должна быть вызвана один раз в любом случае.
public boolean booleanExpression(boolean a, boolean b, boolean c) {
    return (c & secretFunction() || (a ^ b));
}