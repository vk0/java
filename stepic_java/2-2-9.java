// Реализуйте метод, проверяющий, является ли заданное число степенью двойки. Степени двойки со знаком "-" тоже должны распознаваться.
// Если для решения задачи вам требуются циклы или условные операторы, то можете вернуться к ней после просмотра соответствующих уроков. Хотя решить можно и без них.
// Воспользуйтесь предоставленным шаблоном. Декларацию класса, метод main и обработку ввода-вывода добавит проверяющая система.

// Sample Input 1:
// 0
// Sample Output 1:
// false
// Sample Input 2:
// 1
// Sample Output 2:
// true
// Sample Input 3:
// -2
// Sample Output 3:
// true

/**
 * Checks if given <code>value</code> is a power of two.
 *
 * @param value any number
 * @return <code>true</code> when <code>value</code> is power of two, <code>false</code> otherwise
 */
public static boolean isPowerOfTwo(int value) {
        if (value == 0) {
            return false;
        }
        else {
            int num = Math.abs(value);
            return (num & (num - 1)) == 0;
        }
}