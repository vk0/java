// To determine if a number is prime, you have to prove that it's not not prime; because a primality algorithm should stop as soon as all possible divisors are checked, it will always perform at a worst-case scenario level when checking a prime number.

// Consider the code below, which has  algorithms for determining primality, ordered and labeled from worst to best. This code is immediately preceded by  sample outputs for very large prime numbers using each of the algorithms; observe the (often drastic) performance differences between each one.

// When the prime number  is entered, it produces the following output:
// isPrimeWorst performed 2147483646 checks, determined 2147483647 is PRIME.
// isPrimeLessWorst performed 1073741823 checks, determined 2147483647 is PRIME.
// isPrimeGood performed 46341 checks, determined 2147483647 is PRIME.
// isPrimeBest performed 23170 checks, determined 2147483647 is PRIME.
// When the prime number  is entered, it produces the following output:
// isPrimeWorst performed 1073741830 checks, determined 1073741831 is PRIME.
// isPrimeLessWorst performed 536870915 checks, determined 1073741831 is PRIME.
// isPrimeGood performed 32769 checks, determined 1073741831 is PRIME.
// isPrimeBest performed 16384 checks, determined 1073741831 is PRIME.
// When the prime number  is entered, it produces the following output:
// isPrimeWorst performed 536870908 checks, determined 536870909 is PRIME.
// isPrimeLessWorst performed 268435454 checks, determined 536870909 is PRIME.
// isPrimeGood performed 23171 checks, determined 536870909 is PRIME.
// isPrimeBest performed 11585 checks, determined 536870909 is PRIME.
// Note: This sample code below contains count variables and calls to a print function for the purposes of printing the results shown above.

import java.util.*;

class Primality{
    private static void printStats(int count, int n, boolean isPrime){
        String caller = Thread.currentThread().getStackTrace()[2].getMethodName();
        System.err.println( caller + " performed " + count + " checks, determined " + n
        + ( (isPrime) ? " is PRIME." : " is NOT PRIME." ) );
    }
    /**
    *   Worst: O(n) algorithm
    *     Checks if n is divisible by any number from 4 to n.
    *
    *   @param n An integer to be checked for primality.
    *   @return true if n is prime, false if n is not prime.
    **/
    public static boolean isPrimeWorst(int n){
        int count = 0;
        // 1 is not prime
        if( n == 1 ){
            printStats(++count, n, false);
            return false;
        }

        // return false n is divisible by any i from 2 to n
        int i = 1;
        while( i++ < n - 1 ){
            count++;
            if( n % i == 0 ){
                printStats(++count, n, false);
                return false;
            }
        }

        // n is prime
        printStats(++count, n, true);
        return true;
    }

    /**
    *   Better: O(n) algorithm
    *    Checks if n is divisible by any number from 2 to n/2,
    *    but is asymptotically the same as isPrimeWorst
    *
    *   @param n An integer to be checked for primality.
    *   @return true if n is prime, false if n is not prime.
    **/
    public static boolean isPrimeLessWorst(int n){
        int count = 0;
        // 1 is not prime
        if( n == 1 ){
            printStats(++count, n, false);
            return false;
        }

        // return false n is divisible by any i from 2 to n
        int i = 1;
        while( i++ < n/2 ){
            count++;
            if( n % i == 0 ){
                printStats(++count, n, false);
                return false;
            }
        }

        // n is prime
        printStats(++count, n, true);
        return true;
    }

    /**
    *   O(n^(1/2)) Algorithm
    *    Checks if n is divisible by any number from 2 to sqrt(n).
    *
    *   @param n An integer to be checked for primality.
    *   @return true if n is prime, false if n is not prime.
    **/
    public static boolean isPrimeGood(int n){
        int count = 0;
        // 1 is not prime
        if( n == 1 ){
            printStats(++count, n, false);
            return false;
        }
        else if( n == 2 ){
            printStats(++count, n, true);
            return true;
        }

        // return false n is divisible by any i from 2 to n
        int i = 1;
        while( i++ < Math.sqrt(n) ){
            count++;
            if( n % i == 0 ){
                printStats(++count, n, false);
                return false;
            }
        }

        // n is prime
        printStats(++count, n, true);
        return true;
    }

    /**
    *   Improved O( n^(1/2)) ) Algorithm
    *    Checks if n is divisible by 2 or any odd number from 3 to sqrt(n).
    *    The only way to improve on this is to check if n is divisible by
    *   all KNOWN PRIMES from 2 to sqrt(n).
    *
    *   @param n An integer to be checked for primality.
    *   @return true if n is prime, false if n is not prime.
    **/
    public static boolean isPrimeBest(int n){
        int count = 0;
        // check lower boundaries on primality
        if( n == 2 ){
            printStats(++count, n, true);
            return true;
        } // 1 is not prime, even numbers > 2 are not prime
        else if( n == 1 || (n & 1) == 0){
            printStats(++count, n, false);
            return false;
        }

        // Check for primality using odd numbers from 3 to sqrt(n)
        for(int i = 3; i <= Math.sqrt(n); i += 2){
            count++;
            // n is not prime if it is evenly divisible by some 'i' in this range
            if( n % i == 0 ){
                printStats(++count, n, false);
                return false;
            }
        }
        // n is prime
        printStats(++count, n, true);
        return true;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()) {
            int n = scan.nextInt();
            isPrimeWorst(n);
            isPrimeLessWorst(n);
            isPrimeGood(n);
            isPrimeBest(n);
            System.out.println();
        }
        scan.close();
    }
}


// Problem Setter's code :

import java.util.*;

public class Solution {

    static boolean isPrime(int n) {
        for(int i=2;i<Math.sqrt(n);i++) {
            if(n%i==0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfTests = sc.nextInt();
        for (int i = 0; i < numOfTests; i++) {
            int x = sc.nextInt();
            String s;
            if (x >= 2 && isPrime(x)) {
                s = "Prime";
            } else {
                s = "Not prime";
            }
            System.out.println(s);
        }
    }
}

// Problem Tester's code :
// import java.util.*;

// public class Solution {
//     /**
//     *   Improved O( n^(1/2)) ) Algorithm
//     *    Checks if n is divisible by 2 or any odd number from 3 to sqrt(n).
//     *    The only way to improve on this is to check if n is divisible by KNOWN PRIMES from 2 to sqrt(n).
//     *
//     *   @param n An integer to be checked for primality.
//     *   @return true if n is prime, false if n is not prime.
//     **/
//     public static boolean isPrime(int n){
//         // check lower boundaries on primality
//         if( n == 2 ){
//             return true;
//         } // 1 is not prime, even numbers > 2 are not prime
//         else if( n == 1 || (n & 1) == 0){
//             return false;
//         }

//         // Check for primality using odd numbers from 3 to sqrt(n)
//         for(int i = 3; i <= Math.sqrt(n); i += 2){
//             // n is not prime if it is evenly divisible by some 'i' in this range
//             if( n % i == 0 ){
//                 return false;
//             }
//         }
//         // n is prime
//         return true;
//     }

//     public static void main(String[] args) {
//         Scanner scan = new Scanner(System.in);
//         int testCases = scan.nextInt();
//         for(int i = 0; i < testCases; i++){
//             System.out.println(
//                 (isPrime(scan.nextInt()) ? "Prime" : "Not prime") );
//         }
//         scan.close();
//     }
// }