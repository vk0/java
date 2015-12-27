package ex3_equals;

/**
 * Created by igor on 24.05.15.
 */
public class Main2 {
    public static void main(String[] args) {
        Cat cat1 = new Cat("Tom");
        Cat cat2 = new Cat("Tom");

//        string1 = string2;

        if (cat1 == cat2) {
            System.out.println("equals");
        } else {
            System.out.println("not equals");
        }

        if (cat1.equals(cat2)) {
            System.out.println("equals");
        } else {
            System.out.println("not equals");
        }
    }
}
