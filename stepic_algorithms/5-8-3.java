// Задача на программирование: сортировка подсчётом


// Первая строка содержит число 1≤n≤104, вторая — n натуральных чисел, не превышающих 10. Выведите упорядоченную по неубыванию последовательность этих чисел.

// Sample Input:

// 5
// 2 3 9 2 9

// Sample Output:

// 2 2 3 9 9

import java.io.IOException;
public class Main {
    public static void main(String[] args) throws IOException {
        int[] map = new int[10];
        int[] values = new int[nextInt()];
        for (int i = 0; i < values.length; i++) values[i] = nextInt();
        for (int value : values) map[value]++;
        int index = values.length - 1;
        for (int i = map.length - 1; i >= 0; --i) {
            if (map[i] != 0) {
                for (int j = map[i]; j > 0; j--) values[index--] = i;
            }
        }
        for (int value : values) {
            System.out.print(value);
            System.out.print(' ');
        }
    }

    private static int nextInt() throws IOException {
        int d;
        int val = 0;
        while ((d = System.in.read()) == ' ') ;
        boolean sign = false;
        do {
            if (d == '-') {
                sign = true;
                continue;
            }
            val += d - 48;
            val *= 10;
        } while ((d = System.in.read()) > 47 && d < 58);
        if (sign) val *= -1;
        return val / 10;
    }
}