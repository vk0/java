package ex0_stackoverflow;

/**
 * Created by igor on 24.05.15.
 */
public class Main {

    private static int i;

    public static void main(String[] args) {
        test();
    }

    private static void test() {
        System.out.println("testing... " + i++);
        test();
    }
}
