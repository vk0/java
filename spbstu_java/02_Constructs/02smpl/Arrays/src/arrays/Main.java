/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package arrays;

import java.util.Arrays;

/**
 *
 * @author Mike
 */
public class Main {

    static void findMinusOne(int[][] arr2d) {
        L1:
        for (int i=0; i<arr2d.length; i++) {
            for (int j=0; j<arr2d[i].length; j++) {
                if (arr2d[i][j]==-1) {
                    System.out.println("i="+i+" j="+j);
                    break L1;
                }
            }
        }
    }



    static int getArraySum(int[] arr) {
        int sum = 0;
        for (int elem: arr)
            sum += elem;
        return sum;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int[] arr = new int[10];
        int[] arr2 = new int[] { 2, 3, 4};
        int[] arr3 = arr;
        System.out.println("arr = " + arr + "   arr2 = " + arr2 +
                "   arr3 = " + arr3);
        //System.out.println(arr2[3]);
        System.out.println("sum = " + getArraySum(arr));
        int[][] arr2d = new int[3][];
        for (int i=0; i<3; i++)
            arr2d[i] = new int[2];
        arr2d[1][1] = -1;
        arr2d[2][0] = -1;
        findMinusOne(arr2d);
        int[] arr4 = new int[] { 2, 3, 4 };
        if (Arrays.equals(arr2, arr4))
            System.out.println("arrays are equal!");
    }

}
