import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {

    private long gcd(long a, long b) {
        while (true) {
            System.out.println(a + " " + b);
            if (a == 0) return b;
            if (b == 0) return a;
            if (a >= b) {
                a %= b;
            } else {
                b %= a;
            }
        }
    }

    private void run() {
        System.out.println(gcd(1141 * 2231, 1141 * 5412));
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new Main().run();
        long finishTime = System.currentTimeMillis();
        System.out.println(finishTime - startTime + " ms");
    }
}