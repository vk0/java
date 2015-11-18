// Задача на программирование: число инверсий
// Первая строка содержит число 1≤n≤105, вторая — массив A[1…n], содержащий натуральные числа, не превосходящие 109. Необходимо посчитать число пар индексов 1≤i<j≤n, для которых A[i]>A[j]. (Такая пара элементов называется инверсией массива. Количество инверсий в массиве является в некотором смысле его мерой неупорядоченности: например, в упорядоченном по неубыванию массиве инверсий нет вообще, а в массиве, упорядоченном по убыванию, инверсию образуют каждые два элемента.)



// Sample Input:

// 5
// 2 3 9 2 9

// Sample Output:

// 2

import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static int[] array;
    public static BigInteger n_inv = BigInteger.ZERO;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

      if(n < 1){
        System.out.println(0);
        return;
      }

        array = new int[n];
        for(int i = 0; i < n; i++)
            array[i] = sc.nextInt();

        int[] sol = invSort(0, n-1);
        System.out.println(n_inv.toString());
    }

    public static int[] invSort(int l, int r){
        if(l >= r){
            int[] s = {array[l]};
            return s;
        }

        int m = (l + r)/2;
        return merge(invSort(l, m), invSort(m+1, r));
    }

    public static int[] merge(int[] left, int[] right){
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        while(k < result.length){
            if(i < left.length && j < right.length){
                if(left[i] <= right[j]){
                    result[k] = left[i];
                    i++;
                } else {
                    result[k] = right[j];
                    j++;

                    n_inv = n_inv.add(new BigInteger(Integer.toString(left.length - i)));
                }
                k++;
            } else if(i < left.length){
                result[k] = left[i];
                k++;
                i++;
            } else if(j < right.length){
          result[k] = right[j];
          j++;
          k++;
            }
        }
        // System.out.println("\nnum inversions: " + numinv);
        return result;
    }
}