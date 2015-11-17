// Задача на программирование: различные слагаемые

// По данному числу 1≤n≤109 найдите максимальное число k, для которого n можно представить как сумму k различных натуральных слагаемых. Выведите в первой строке число k, во второй — k слагаемых.

// Sample Input 1:

// 4

// Sample Output 1:

// 2
// 1 3


// Sample Input 2:

// 6

// Sample Output 2:

// 3
// 1 2 3

import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt(), i = 0, s = 0;
        int z = k;
        HashSet<Integer> set = new HashSet<>();
        while (k > 0) {
            k -= ++i;
            s += i;
            set.add(i);
        }
        set.remove(s - z);
        System.out.println(set.size());
        set.forEach(x -> System.out.print(x + " "));
    }
}