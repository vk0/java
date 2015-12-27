package ex2_static;

/**
 * Created by igor on 24.05.15.
 */
public class Main {
    public static void main(String[] args) {
        Cat cat1 = new Cat("Tom");
        cat1.showCatsAmount();
        Cat cat2 = new Cat("Murka");
        cat2.showCatsAmount();
        Cat cat3 = new Cat("Kitty");
        cat3.showCatsAmount();
    }
}
