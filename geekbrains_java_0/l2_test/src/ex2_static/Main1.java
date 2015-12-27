package ex2_static;

/**
 * Created by igor on 24.05.15.
 */
public class Main1 {
    public static void main(String[] args) {
        Cat cat1 = new Cat("Tom");
//        Cat cat2 = new Cat("Tom", 2);
//        System.out.println(cat1.catsAmount); // не корректно
//        System.out.println(Cat.catsAmount);
        Cat.staticShowCatsAmount();
//        cat1.staticShowCatsAmount(); // не стоит делать

//        Field field = new Field();
        Field field = Field.instance;

        Point point = Point.getRandomPoint();
        System.out.println(point.getX());
    }
}
