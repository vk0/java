// Дан класс ComplexNumber. Переопределите в нем методы equals() и hashCode() так, чтобы equals() сравнивал экземпляры ComplexNumber по содержимому полей re и im, а hashCode() был бы согласованным с реализацией equals().

// Реализация hashCode(), возвращающая константу, засчитана не будет.

// Пример

// ComplexNumber a = new ComplexNumber(1, 1);
// ComplexNumber b = new ComplexNumber(1, 1);
// // a.equals(b) must return true
// // a.hashCode() must be equal to b.hashCode()

public final class ComplexNumber {
    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    @Override
    public double hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + re;
        result = prime * result + im;
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        ComplexNumber other = (ComplexNumber) obj;
        if (re != other.re)
            return false;
        if (im != other.im)
            return false;
        return true;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }
}