import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int MOD = (int) (1e9+7);
    List<Integer> cache = new ArrayList<>();
    {
        cache.add(0);
        cache.add(1);
    }

    private int fibonacci(int n) {
        for (int i = cache.size(); i <= n; i++) {
            int res = (cache.get(i - 1) + cache.get(i - 2)) % MOD;
            cache.add(res);
        }
        return cache.get(n);
    }

    private void run(int n) {
        System.out.println(n + ": " + fibonacci(n));
    }

    public static void main(String[] args){
        long startTime = System.currentTimeMillis();
        new Main().run(100000);
        long finishTime = System.currentTimeMillis();
        System.out.println(finishTime - startTime + " ms");
        // for (int i = 0; i < 100; i++) {
        //     long startTime = System.currentTimeMillis();
        //     new Main().run(i);
        //     long finishTime = System.currentTimeMillis();
        //     System.out.println(finishTime - startTime + " ms");
        // }
    }
}