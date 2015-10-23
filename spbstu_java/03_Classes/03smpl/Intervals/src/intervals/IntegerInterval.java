/*
 * $Id:$
 */

package intervals;

/**
 * Интервал целых значений
 * @author Mikhail Glukhikh
 */
public class IntegerInterval implements Cloneable {

    /** Нижняя граница */
    private final int min;
    /** Верхняя граница */
    private final int max;

    /**
     * Конструктор нуля
     */
    public IntegerInterval() {
        this(0, 0);
    }

    /**
     * Конструктор схлопнутого интервала
     * @param value точечное значение
     */
    public IntegerInterval(int value) {
        this(value, value);
    }

    /**
     * Конструктор полноценного интервала
     * @param min нижняя граница
     * @param max верхняя граница
     * @throws IllegalArgumentException если нижняя граница больше верхней
     */
    public IntegerInterval(int min, int max) throws IllegalArgumentException {
        if (min > max)
            throw new IllegalArgumentException(
                    "Нижняя граница " + min + " больше верхней " + max);
        this.min = min;
        this.max = max;
    }

    /**
     * Клонирование
     * @return глубокая копия интервала
     */
    @Override
    public IntegerInterval clone() throws CloneNotSupportedException {
        return (IntegerInterval)super.clone();
    }

    /**
     * Получить нижнюю границу
     * @return нижняя граница
     */
    public int getMin() {
        return min;
    }

    /**
     * Получить верхнюю границу
     * @return верхняя граница
     */
    public int getMax() {
        return max;
    }

    /**
     * Объединиться с интервалом
     * @param variant второй интервал
     * @return результат объединения
     */
    public IntegerInterval disj(IntegerInterval variant) {
        final int min1 = this.getMin();
        final int min2 = variant.getMin();
        final int max1 = this.getMin();
        final int max2 = variant.getMax();
        return new IntegerInterval(min1<min2?min1:min2, max1>max2?max1:max2);
    }

    /**
     * Пересечься с интервалом
     * @param variant второй интервал
     * @return результат пересечения
     * @throws IllegalArgumentException если интервалы не пересекаются
     */
    public IntegerInterval conj(IntegerInterval variant) throws IllegalArgumentException {
        final int min1 = this.getMin(), min2 = variant.getMin();
        final int max1 = this.getMax(), max2 = variant.getMax();
        final int resMin = min1>min2?min1:min2;
        final int resMax = max1<max2?max1:max2;
        if (resMin > resMax)
            throw new IllegalArgumentException(
                    "Интервалы " + this + " и " + variant + " не пересекаются");
        return new IntegerInterval(resMin, resMax);
    }

    /**
     * Операция сложение
     * @param variant второй аргумент
     * @return результат операции
     */
    public IntegerInterval add(IntegerInterval variant) {
        final int rmin = this.getMin() + variant.getMin();
        final int rmax = this.getMax() + variant.getMax();
        return new IntegerInterval(rmin, rmax);
    }

    /**
     * Операция вычитание
     * @param variant второй аргумент
     * @return результат операции
     */
    public IntegerInterval sub(IntegerInterval variant) {
        final int rmin = this.getMin() - variant.getMax();
        final int rmax = this.getMin() - variant.getMax();
        return new IntegerInterval(rmin, rmax);
    }
   
    /**
     * Операция инверсия (-x)
     * @return результат операции
     */
    public IntegerInterval inv() {
        return new IntegerInterval(-getMax(), -getMin());
    }

    /**
     * Преобразование в строку
     * @return строковое представление в форме a:b
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(min);
        sb.append(':');
        sb.append(max);
        return sb.toString();
    }

    /**
     * Сравнение на равенство
     * @param obj сравниваемый объект
     * @return true, если интервалы равны (обе границы совпадают)
     */
    @Override
    public boolean equals(Object obj) {
        if (obj==this)
            return true;
        else if (obj instanceof IntegerInterval) {
            final IntegerInterval var = (IntegerInterval)obj;
            return this.min == var.min && this.max == var.max;
        } else return false;
    }

    /**
     * Хэш-код интервала
     * @return хэш-код
     */
    @Override
    public int hashCode() {
        int hash = 5;
        hash = 29 * hash + this.min;
        hash = 29 * hash + this.max;
        return hash;
    }
}
