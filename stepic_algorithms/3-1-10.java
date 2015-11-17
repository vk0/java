// # Задача на программирование: непрерывный рюкзак


// # Первая строка содержит количество предметов 1≤n≤103 и вместимость рюкзака 0≤W≤2⋅106. Каждая из следующих n строк задаёт стоимость 0≤ci≤2⋅106 и объём 0<wi≤2⋅106 предмета (n, W, ci, wi — целые числа). Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.

// # Sample Input:

// # 3 50
// # 60 20
// # 100 50
// # 120 30

// # Sample Output:

// # 180.000

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        double bagSize = scanner.nextInt();
        int[][] items = new int[count][];
        for (int i = 0; i < count; i++) {
            items[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }
        Arrays.sort(items, (o1, o2) -> Double.compare(((double) o2[0] / o2[1]), (double) o1[0] / o1[1]));
        double result = 0;
        for (int i = 0; bagSize != 0 && i < count; i++) {
            if (bagSize < items[i][1]) {
                result += ((double)items[i][0] / items[i][1]) * bagSize;
                bagSize = 0;
            } else {
                bagSize -= items[i][1];
                result += items[i][0];
            }
        }
        System.out.printf("%1.3f ", result);
    }
}