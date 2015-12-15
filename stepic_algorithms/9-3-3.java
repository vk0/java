//  Практика на Java: Расстояние редактирования

import java.io.IOException;
import java.util.Scanner;

public class Main {

    private String first;
    private String second;

    int[][] d;
    boolean[][] calculated;

    private int editingDistance(int n, int m) {
        if (n == 0 && m == 0) return 0;
        if (n == 0) return m;
        if (m == 0) return n;
        if (calculated[n][m]){
            return d[n][m];
        }
        int res1 = editingDistance(n, m - 1) + 1;
        int res2 = editingDistance(n - 1,m) + 1;
        int res3 = editingDistance(n - 1,m - 1) + (first.charAt(n - 1) == second.charAt(m - 1) ? 0 : 1);
        int result = Math.min(Math.min(res1, res2), res3);
        calculated[n][m] = true;
        d[n][m] = result;
        return result;

    }

    private void run() throws IOException {
        Scanner input = new Scanner(System.in);
        String first = input.next();
        String second = input.next();
        d = new int[first.length() + 1][second.length() + 1];
        System.out.println(editingDistance(first.length(), second.length()));
//        System.out.println(first + " " + second);
    }

    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();
        new Main().run();
        long finishTime = System.currentTimeMillis();
//        System.out.println(finishTime - startTime + " ms");
    }
}
