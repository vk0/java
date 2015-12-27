package ex3_equals;

/**
 * Created by igor on 24.05.15.
 */
public class Main {
    public static void main(String[] args) {
        String string1 = "hello";
//        String string2 = "hello";
        String string2 = new String("hello");

//        string1 = string2;

        if (string1 == string2) {
            System.out.println("equals");
        } else {
            System.out.println("not equals");
        }

        if (string1.equals(string2)) {
            System.out.println("equals");
        } else {
            System.out.println("not equals");
        }
    }
}
