// Create a Map to hold your phone book entries.
// Add nn (name,phoneNumber)(name,phoneNumber) mappings to your phone book.
// For each namename queried, check if your phone book contains it as a key; there are two ways to do this:
// Check if the Map contains the key using the contains method. If contains(key) returns true, then write another line of code to get the value it maps to; if it returns false, then print "Not Found".
// The slightly cleaner approach is to use the get method to retrieve the value mapped to from key and assign it to a variable. If get(key) fails to find key in the map, it will return null. Use the value returned by get(key) as the condition check for your print statement. If the variable is not null, then print the record; otherwise, print "Not found".

// Note: Because phone numbers will only ever be printed and are never going to be used for any sort of numeric calculation, you could also use a String to String mapping (instead of String to Integer)

import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []args){
        Map<String,Integer> phoneBook = new HashMap<String,Integer>();
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for(int i = 0; i < n; i++){
            String name = scan.next();
            int phone = scan.nextInt();
            phoneBook.put(name, phone);
        }
        while(scan.hasNext()){
            String s = scan.next();
            Integer phoneNumber = phoneBook.get(s);
            System.out.println(
                (phoneNumber != null)
                ? s + "=" + phoneNumber
                : "Not found"
            );
        }
        scan.close();
    }
}