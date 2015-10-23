/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package strings;

/**
 *
 * @author Mike
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String s = "Hello, world!";
        String s1 = s;
        System.out.println("s = " + s + "   s1 = " + s1);
        s = "I am glad to see you";
        System.out.println("s = " + s + "   s1 = " + s1);
        String s2 = s + s1;
        String s3 = s + 42;
        System.out.println("s2 = " + s2 + "   s3 = " + s3);
        s = null;
        System.out.println("s = " + s + "   s1 = " + s1);
    }

}
