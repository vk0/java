// For this explanation, the variables provided in your editor are subscripted with a 00, and the corresponding variables declared and initialized by you are subscripted with 11.

// The following variables are already declared and initialized in your editor:
// i0=4i0=4, d0=4.0d0=4.0, and s0="HackerRank "s0="HackerRank ".

// The following variables were read from stdin:
// i1=12i1=12, d1=4.0d1=4.0, and s1="is the best place to learn and practice coding!"s1="is the best place to learn and practice coding!".

// Our first line of output is the result of i0+i1i0+i1.
// Our second line of output is the result of d0+d1d0+d1.
// Our third line of output is the result of s0+s1s0+s1.

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

   public static void main(String[] args) {
        int i = 4;
        double d = 4.0;
        String s = "HackerRank ";

        Scanner scan = new Scanner(System.in);
        /* Declare second integer, double, and String variables. */
        int i2;
        double d2;
        String s2;

        /* Read and save an integer, double, and String to your variables.*/
        i2 = scan.nextInt();
        d2 = scan.nextDouble();
        scan.nextLine(); // read the rest of the line of input (newline character after the double token).
        s2 = scan.nextLine();

        /* Print the sum of both integer variables on a new line. */
        System.out.println(i + i2);

        /* Print the sum of the double variables on a new line. */
        System.out.println(d + d2);

        /* Concatenate and print the String variables on a new line integer variables on a new line;
           the 'string` variable above should be printed first. */
        System.out.println(s + s2);

        scan.close();
   }
}
