/**
 * Created by igor on 17.05.15.
 */
public class Main2 {
    public static void main(String[] args) {
        // Примитивные типы
        byte bt = 127;
        System.out.println(Byte.MAX_VALUE);

        short sh = 32000;
        System.out.println(Short.MAX_VALUE);

        int i = 2147483647; // по умолчанию
        System.out.println(Integer.MAX_VALUE);

        long l = 2147483647000000000L;
        System.out.println(Long.MAX_VALUE);

//        char ch = 23355;
        char ch = 2395;
//        char ch = 'D';
        System.out.println(ch);

        String s = "Hello";
        System.out.println(s);

        boolean b = true;
        System.out.println(b);

        double d = 12.3; // по умолчанию
        System.out.println(d);
        System.out.println(Double.MAX_VALUE);

        float f = 12.3f;
//        float f2 = 20000L;
        System.out.println(Float.MAX_VALUE);

        Void d2 = null;

//        BigDecimal ds;
//        BigInteger ss;
    }
}
