import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {

    private int gcd(int a, int b) {
        int result = 0;
        for (int i = 1; i <= Math.max(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                result = i;
            }
        }
        return result;
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