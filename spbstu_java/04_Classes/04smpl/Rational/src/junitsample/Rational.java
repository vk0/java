/*
 * $Id:$
 */

package junitsample;

/**
 * Рациональное число.
 * Класс реализован как immutable - неизменяемый
 * @author Eugene V. Pychkine
 * @author Mikhail I. Glukhikh
 */
public class Rational implements Comparable<Rational>, Cloneable {
    /** Числитель */
    private final int num;
    /** Знаменатель */
    private final int denom;

    /**
     * Конструктор нуля
     */
    public Rational() {
        this( 0, 1 );
    }

    /**
     * Общий конструктор рационального числа.
     * Сразу же осуществляет упрощение.
     * @param num числитель
     * @param denom знаменатель
     * @throws ArithmeticException если знаменатель равен нулю
     */
    public Rational( int num, int denom ) throws ArithmeticException {
        if (denom == 0)
            throw new ArithmeticException("Рациональное число с нулевым знаменателем");
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
        if (num != 0) {
            int divisor = MyMath.gcd(num, denom);
            num /= divisor;
            denom /= divisor;
        }
        this.num = num;
        this.denom = denom;
    }

    /**
     * Получить числитель
     * @return числитель
     */
    public int getNum() {
        return num;
    }

    /**
     * Получить знаменатель
     * @return знаменатель
     */
    public int getDenom() {
        return denom;
    }

    /**
     * Сравнение чисел на равенство
     * @param arg сравниваемый объект
     * @return true если числа равны
     */
    @Override
    public boolean equals(Object arg ) {
        if (arg==this)
            return true;
        if (arg instanceof Rational)
            return num==((Rational)arg).num && denom==((Rational)arg).denom;
        return false;
    }

    /**
     * Расчет хэш-кода
     * @return хэш-код
     */
    @Override
    public int hashCode() {
        int hash = 3;
        hash = 79 * hash + this.num;
        hash = 79 * hash + this.denom;
        return hash;
    }

    /**
     * Сложить число с указанным. Не меняет число и аргумент.
     * @param arg второе число
     * @return результат сложения
     */
    public Rational add( Rational arg ) {
        return new Rational(
                num*arg.denom + arg.num*denom,
                denom * arg.denom);
    }

    /**
     * Инвертировать число. Не меняет число.
     * @return результат инвертирования
     */
    public Rational inv() {
        return new Rational(
                -num, denom);
    }

    /**
     * Вычесть указанное число из нашего. Не меняет число и аргумент.
     * @param arg вычитаемое число
     * @return результат вычитания
     */
    public Rational sub( Rational arg ) {
        return add(arg.inv());
    }

    /**
     * Сравнить число с указанным
     * @param o второе число
     * @return 1, если наше число больше, -1, если меньше, 0, если числа равны
     */
    @Override
    public int compareTo(Rational o) {
        Rational res = this.sub(o);
        if (res.num > 0)
            return 1;
        else if (res.num == 0)
            return 0;
        else
            return -1;
    }

    /**
     * Получить строковое представление
     * @return строковое представление
     */
    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append(num);
        if (denom > 1) {
            sb.append("/");
            sb.append(denom);
        }
        return sb.toString();
    }

    /**
     * Клонировать рациональное число
     * @return глубокая копия числа
     */
    @Override
    public Rational clone() {
        try {
            return (Rational)super.clone();
        } catch (CloneNotSupportedException ex) {
            // Не должны попадать сюда
            throw new AssertionError("Неожиданное исключение: " + ex);
        }
    }
}
