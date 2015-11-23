import java.util.HashMap;

public class Main {
    Map<Integer, Integer> cache = new HashMap<>();

    int cnt;

    private int fibonacci(int n) {
        cnt++;
        if (n < 2) {
            return n;
        }
        if (cache.containsKey(n)){
            return cache.get(n);
        } else {
            int res = fibonacci(n - 1) + fibonacci(n - 2);
            cache.put(n, res);
            return res;
        }

    }

    private void run(int n) {
        System.out.println(n + ": " + fibonacci(n));
        System.out.println(cnt + " calls");
    }

    public static void main(String[] args){
        for (int i = 0; i < 100; i++) {
            long startTime = System.currentTimeMillis();
            new Main().run(i);
            long finishTime = System.currentTimeMillis();
            System.out.println(finishTime - startTime + " ms");
        }
    }
}