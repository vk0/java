/*
 * $Id:$
 */

package calc;

import java.util.NoSuchElementException;

/**
 * Класс "Арифметический стек"
 * @author Mikhail Glukhikh
 */
public class ArithmeticStack extends Stack<Double> {

    /**
     * Вспомогательный класс "вычислительная операция"
     */
    public static enum Operation {
        /** Сложение */
        ADD,
        /** Вычитание */
        SUB,
        /** Умножение */
        MUL,
        /** Деление */
        DIV
    };

    /**
     * Вытолкнуть два верхних числа из стека,
     * сложить их и затолкнуть обратно результат
     * @throws NoSuchElementException если в стеке нет двух чисел
     */
    public void add() throws NoSuchElementException {
        push(pop() + pop());
    }

    /**
     * Вытолкнуть два верхних числа из стека,
     * вычесть их (из нижнего верхнее) и затолкнуть обратно результат
     * @throws NoSuchElementException если в стеке нет двух чисел
     */
    public void sub() throws NoSuchElementException {
        double x = pop();
        double y = pop();
        push(y - x);
    }

    /**
     * Вытолкнуть два верхних числа из стека,
     * перемножить их и затолкнуть обратно результат
     * @throws NoSuchElementException если в стеке нет двух чисел
     */
    public void mul() throws NoSuchElementException {
        push(pop() * pop());
    }

    /**
     * Вытолкнуть два верхних числа из стека,
     * поделить их (нижнее на верхнее) и затолкнуть обратно результат
     * @throws NoSuchElementException если в стеке нет двух чисел
     */
    public void div() throws NoSuchElementException {
        double x = pop();
        double y = pop();
        push(y / x);
    }

    /**
     * Выполнить операцию, указанную аргументом
     * @param op требуемая операция
     * @throws NoSuchElementException если в стеке меньше чисел,
     * чем есть аргументов у операции
     */
    public void execute(Operation op) throws NoSuchElementException {
        double x = pop();
        double y = pop();
        switch (op) {
            case ADD:
                push(x + y);
                break;
            case SUB:
                push(y - x);
                break;
            case MUL:
                push(x * y);
                break;
            case DIV:
                push(y / x);
                break;
        }
    }
}
