// Here is a breakdown of the problem:
// We are given  numbers,  (the size of our set) and  (a constraint on the number we choose for our output).
// We must have a set of integers from  to  that we'll refer to as .
// We must have  integers,  and , that are elements of . These are constrained by the rule that . We implement this with nested loops.
// We must find find the bitwise AND for every possible  and . We'll refer to this as  (result).
// We must print the maximum  as our answer.

import java.util.*;

public class Solution {
    public static int findMaximum(int n, int k){
        int max = 0;
        int a = n - 1; // we are constrained by a < b
        while(a-- > 0) {
            for(int b = a + 1; b <= n; b++){
                int test = a & b;
                if(     test < k
                    &&  test > max ){
                    max = test;
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i = 0; i < t; i++){
            int n = in.nextInt();
            int k = in.nextInt();
            System.out.println( findMaximum(n, k) );
        }
        in.close();
    }
}