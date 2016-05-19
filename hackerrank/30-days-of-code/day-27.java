import java.util.*;

public class Solution {
    Solution(int n, int k, int[] a){
        System.out.println(n + " " + k);
        for(int i = 0; i < n; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // number of test cases - each test case is two lines
        int testCases = 5;

        System.out.println(testCases);
        new Solution(4, 3, new int[] {-1, 0, 4, 2});
        new Solution(5, 2, new int[] {0, -1, 2, 1, 4});
        new Solution(7, 6, new int[] {2, 0, -1, 1 , 1 , 1, 1});
        new Solution(3, 1, new int[] {-1, 0, 4});
        new Solution(6, 4, new int[] {0, -1, 1, 4, 5, 6});
    }
}


// class Solution{
//     public static void main(String srgs[]){
//     System.out.println(5);
//     System.out.println("4 3");
//     System.out.println("0 -3 4 2");
//     System.out.println("5 2");
//     System.out.println("0 -3 4 2 2");
//     System.out.println("3 3");
//     System.out.println("0 -3 4");
//     System.out.println("7 2");
//     System.out.println("0 -3 1 1 1 1 1");
//     System.out.println("6 3");
//     System.out.println("0 -3 4 2 1 1");
//     }
// }