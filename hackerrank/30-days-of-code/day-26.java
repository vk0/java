// To calculate the fine, we must first compare the  and the , then the  to the , and finally the  to the . The should be initialized to .

// Years:
// If , then the book was returned early and .
// If , then .
// If , then the book was either returned on time or was returned less than a year late; to determine this, we move on to our Months logic.

// Months:
// If , then the book was returned early and .
// If , then the book was returned some number of months late and .
// If , then the book was either returned on time or less than a month late; to determine this, we move on to our Days logic.

// Days:
// If , then .
// If , then .

import java.util.*;

class BookReturnDate{
    public int day;
    public int month;
    public int year;

    BookReturnDate(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
}

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BookReturnDate actual = new BookReturnDate(scan.nextInt(), scan.nextInt(),scan.nextInt());
        BookReturnDate expected = new BookReturnDate(scan.nextInt(), scan.nextInt(),scan.nextInt());
        scan.close();

        int fine = 0;

        // Returned within the current year:
        if(expected.year == actual.year){
            // Returned 1+ months late in current year
            if(expected.month < actual.month){
                fine = (actual.month - expected.month) * 500;
            }
            // Returned 1+ days late within the current month
            else if( (expected.month == actual.month)
                    && (expected.day < actual.day) ){
                fine = (actual.day - expected.day) * 15;
            }
            // Else it is implied that the book was returned early
        }
        else if(expected.year < actual.year){
            // Returned 1+ years late
            fine = 10000;
        }
        // Else it is implied that the book was returned 1+ years early

        System.out.println(fine);

    }
}

// Problem Tester's code :
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String s1=br.readLine().trim();
        String s2=br.readLine().trim();
        StringTokenizer st=new StringTokenizer(s1);
        int d1=Integer.parseInt(st.nextToken());
        int m1=Integer.parseInt(st.nextToken());
        int y1=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(s2);
        int d2=Integer.parseInt(st.nextToken());
        int m2=Integer.parseInt(st.nextToken());
        int y2=Integer.parseInt(st.nextToken());
        int fine=0;
        if(y1>y2){
            fine=10000;
        }
        else if(m1>m2){
            fine=(m1-m2)*500;
        }
        else if(d1>d2){
            fine=(d1-d2)*15;
        }
        System.out.println(fine);



    }
}