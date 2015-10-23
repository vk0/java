/*
 * $Id:$
 */

package calc;

import calc.ArithmeticStack.Operation;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.TreeMap;

/**
 * Класс для вычисления выражений в обратной польской записи
 * @author Mikhail Glukhikh
 */
public class Polish {

    /**
     * Ассоциативный массив "строковое представление операции" - "операция"
     */
    static Map<String, Operation> operationMap = new HashMap<String, Operation>();
    static {
        // Выполняем статическую инициализацию массива
        operationMap.put("+", Operation.ADD);
        operationMap.put("-", Operation.SUB);
        operationMap.put("*", Operation.MUL);
        operationMap.put("/", Operation.DIV);
    }

    /**
     * <p>Рассчитать значение выражения в обратной польской записи.</p>
     *
     * <p>Элементы выражения должны быть отделены друг от друга
     * ОДНИМ пробелом. Элементы могут быть вещественными числами
     * и арифметическими операциями.</p>
     *
     * @param expr выражение в обратной польской записи
     * @return результат расчета выражения
     * @throws IllegalArgumentException если в выражении есть
     * недопустимые элементы или нарушен порядок операций
     */
    static public double calc(String expr) throws IllegalArgumentException {
        final ArithmeticStack stack = new ArithmeticStack();
        final String[] args = expr.split(" ");
        for (String arg: args) {
            try {
                double x = Double.parseDouble(arg);
                stack.push(x);
            } catch (NumberFormatException e) {
                Operation op = operationMap.get(arg);
                if (op==null) {
                    throw new IllegalArgumentException(
                            "Не могу разобрать элемент выражения " + arg);
                }
                try {
                    stack.execute(op);
                } catch (NoSuchElementException ex) {
                    throw new IllegalArgumentException(
                            "Не могу рассчитать значение выражения " + expr +
                            " ошибка при выполнении операции " + arg, ex);
                }
            }
        }
        return stack.top();
    }
}
