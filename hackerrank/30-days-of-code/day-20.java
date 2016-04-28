import java.util.Scanner;

public class Solution {
    private static int[] array;

    private static void bubbleSort() {
        int n = array.length;

        // number of swaps for all array iterations
        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            // number of swaps for current array iteration
            int numSwaps = 0;

            for (int j = 0; j < array.length - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    numSwaps++;
                    totalSwaps++;
                }
            }

            if (numSwaps == 0) {
                System.out.printf("Array is sorted in %d swaps.\n", totalSwaps);
                System.out.printf("First Element: %d\n", array[0]);
                System.out.printf("Last Element: %d\n", array[n - 1]);

                break;
            }
        }
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = in.nextInt();
        }
        in.close();

        bubbleSort();
    }
}