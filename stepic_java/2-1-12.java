
import java.math.*;

public class Main {
// public boolean doubleExpression(double a, double b, double c) {
//     BigDecimal a1 = BigDecimal.valueOf(a);
//     BigDecimal b1 = BigDecimal.valueOf(b);
//     BigDecimal c1 = BigDecimal.valueOf(c);
//     if (a1.add(b1) == c1){
//         return true;
//     }
//     return false;
//     // return a1 + b1 == c1;
//     }

    public static void main(String[] args) {
        // Main rc = new Main();
        // boolean res = rc.doubleExpression(0.1d, 0.2d, 0.3d);
        double a = 0.1d;
        double b = 0.2d;
        double c = 0.3d;
        BigDecimal a1 = new BigDecimal(a);
        BigDecimal b1 = new BigDecimal(b);
        BigDecimal c1 = new BigDecimal(c);
        // System.out.println(res);
        System.out.println(c1);
        // BigDecimal a1 = BigDecimal.valueOf(a);
        // BigDecimal b1 = BigDecimal.valueOf(b);
        // BigDecimal c1 = BigDecimal.valueOf(c);
        BigDecimal res = a1.add(b1);
        // BigDecimal res1 = BigDecimal.valueOf(res);
        System.out.println(res.compareTo(c1) == 0 ? "true": "false");
        // if (res == c1){
        //     System.out.println(res);
        // }
        System.out.println(res);
        String bbb = "0";
        String ccc = "1";
        int H1 = 0;
        int H2 = 1;
        int H3 = H1 ^ H2;
        int aaa = Integer.parseInt(bbb);
        int ddd = Integer.parseInt(ccc);
        System.out.println(H3);
        // System.out.println( "a XOR b " + Integer.toBinaryString( aaa ^ ddd ));

        // System.out.println(c1);
        // res = a + b;
        // System.out.println(res); //0.30000000000000004
        // System.out.println("It's alive! It's alive!");

}
}

// public boolean doubleExpression(double a, double b, double c) {
//     BigDecimal a1 = BigDecimal.valueOf(a);
//     BigDecimal b1 = BigDecimal.valueOf(b);
//     BigDecimal c1 = BigDecimal.valueOf(c);
//     BigDecimal res = a1.add(b1);
//     System.out.println(res.compareTo(c1) == 0 ? "true": "false");
//     // return a + b == c;
// }