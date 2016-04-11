// You must lay out your logic to ensure that ansans is being changed only when a specific condition is met. By starting at the top of our condition range (i.e.: >20>20) and moving backwards, we remove the need need to check for additional conditions.

// Because there are two output strings (either "Weird" or "Not Weird") but four conditional statements changing ansans to one of those two values, you could also save the strings as variables. This would be beneficial for two reasons:
// It reduces the likelihood of uncaught typos or spelling errors.
// If we ever need to change one of the statements (e.g.: "Weird" must be "Weird!" instead), we only need to change it in one place.

import java.util.*;

public class Solution {
    private static String weird = "Weird";
    private static String notWeird = "Not Weird";
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();
        String ans="";

        // if 'n' is NOT evenly divisible by 2 (i.e.: n is odd)
        if(n%2==1){
            ans = weird;
        }
        // 'n' must be even; proceed if 'n' >= 2
        else if(n >= 2){
            if(n > 20){
                ans = notWeird;
            }
            else if(n >= 6){
                ans = weird;
            }
            else if(n >= 2){
                ans = notWeird;
            }
        }
        System.out.println(ans);
    }
}