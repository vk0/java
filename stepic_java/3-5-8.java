// Напишите класс AsciiCharSequence, реализующий компактное хранение последовательности ASCII-символов (их коды влезают в один байт) в массиве байт. По сравнению с классом String, хранящим каждый символ как char, AsciiCharSequence будет занимать в два раза меньше памяти.

// Класс AsciiCharSequence должен:

// реализовывать интерфейс java.lang.CharSequence;
// иметь конструктор, принимающий массив байт;
// определять методы length(), charAt(), subSequence() и toString()
// Сигнатуры методов и ожидания по их поведению смотрите в описании интерфейса java.lang.CharSequence (JavaDoc или исходники).

// P.S. В Java 9 ожидается подобная оптимизация в самом классе String: http://openjdk.java.net/jeps/254

public class AsciiCharSequence implements CharSequence {
    private byte[] data;

    public AsciiCharSequence(byte[] data) {
        this.data = data;
    }

    @Override
    public int length() {
        return data.length;
    }

    @Override
    public char charAt(int index) {
        return (char) (data[index] & 0xff);
    }

    @Override
    public CharSequence subSequence(int start, int end) {
        int length = end - start;
        byte[] bytes = new byte[length];
        for (int i = 0, j = start; i < length; i++, j++) {
            bytes[i] = data[j];
        }
        return new AsciiCharSequence(bytes);
    }

    @Override
    public String toString() {
        return new String(data);
    }
}