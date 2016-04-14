import java.io.*;
    import java.util.*;
    import java.text.*;
    import java.math.*;
    import java.util.regex.*;

    public class Solution {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int tests = sc.nextInt();
            sc.nextLine();
            for (int i = 0; i < tests; i++) {
                String s = sc.nextLine();
                boolean isFunny = true;
                int start = 0;
                int end = s.length() - 1;
                while (start < s.length() - 2 && end > 0) {
                    int first=(int)s.charAt(start);
                    int last=(int)s.charAt(end);
                    int secondFirst=(int)s.charAt(start+1);
                    int secondLast=(int)s.charAt(end-1);
                    if(Math.abs(first-secondFirst)!=Math.abs(last-secondLast)) {
                        isFunny = false;
                        break;
                    }
                    start++;
                    end--;
                }
                if (isFunny) {
                    System.out.println("Funny");
                } else {
                    System.out.println("Not Funny");
                }
            }
        }
    }