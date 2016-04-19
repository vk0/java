import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[][] = new int[6][6];
        for(int i=0; i < 6; i++){
            for(int j=0; j < 6; j++){
                arr[i][j] = in.nextInt();
            }
        }
        int sum = -10000;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {

                // [00] [01] [02]
                //      [11]
                // [20] [21] [22]

                int currentSum = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                    + arr[i+1][j+1]
                    + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                if (currentSum > sum) {
                    sum = currentSum;
                }
            }
        }

        System.out.println(sum);
    }
}


// public class Solution {
//     private static final int _MAX = 6; // size of matrix
//     private static final int _OFFSET = 2; // hourglass width
//     private static int matrix[][] = new int[_MAX][_MAX];
//     private static int maxHourglass = -63; // initialize to lowest possible sum (-9 x 7)

//     /** Given a starting index for an hourglass, sets maxHourglass
//     *   @param i row
//     *   @param j column
//     **/
//     private static void hourglass(int i, int j){
//         int tmp = 0; // current hourglass sum

//         // sum top 3 and bottom 3 elements
//         for(int k = j; k <= j + _OFFSET; k++){
//             tmp += matrix[i][k];
//             tmp += matrix[i + _OFFSET][k];
//         }
//         // sum middle element
//         tmp += matrix[i + 1][j + 1];

//         if(maxHourglass < tmp){
//             maxHourglass = tmp;
//         }
//     }

//     public static void main(String[] args) {
//         // read inputs
//         Scanner scan = new Scanner(System.in);
//         for(int i=0; i < _MAX; i++){
//             for(int j=0; j < _MAX; j++){
//                 matrix[i][j] = scan.nextInt();
//             }
//         }
//         scan.close();

//         // find maximum hourglass
//         for(int i=0; i < _MAX - _OFFSET; i++){
//             for(int j=0; j < _MAX - _OFFSET; j++){
//                 hourglass(i, j);
//             }
//         }

//         // print maximum hourglass
//         System.out.println(maxHourglass);
//     }
// }