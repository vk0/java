// Реализуйте метод, вычисляющий факториал заданного натурального числа.
// Факториал N вычисляется как 1⋅2⋅...⋅N.
// Поскольку это очень быстро растущая функция, то даже для небольших N вместимости типов int и long очень скоро не хватит. Поэтому будем использовать BigInteger.
// Воспользуйтесь предоставленным шаблоном. Декларацию класса, метод main и обработку ввода-вывода добавит проверяющая система.
// Sample Input 1:
// 1
// Sample Output 1:
// 1
// Sample Input 2:
// 3
// Sample Output 2:
// 6
/**
 * Calculates factorial of given <code>value</code>.
 *
 * @param value positive number
 * @return factorial of <code>value</code>
 */
public static BigInteger factorial(int value) {
    if (value == 1) {
        return BigInteger.valueOf(1);
    }
    else {
        return BigInteger.valueOf(value).multiply(factorial(value-1));
    }
}