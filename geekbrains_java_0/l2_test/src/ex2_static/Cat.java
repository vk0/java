package ex2_static;

/**
 * Created by igor on 24.05.15.
 */
public class Cat {
    String name;
    int age = 10; // = 0 при создании очередной кошки
    static int catsAmount; // не будут пересоздаваться


    static { // блок инициализации
//        age = 20; // нельзя
        catsAmount = 100;
    }

    { // блок инициализации
        age = 20;
        catsAmount = 100;
    }

    public Cat(String name) {
        this.name = name;
        catsAmount++;
    }

    public Cat(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void about() {
        System.out.println(name);
    }

    void showCatsAmount() {
        System.out.println(catsAmount);
    }

    static void staticShowCatsAmount() {
        System.out.println(catsAmount);
//        about(); // нельзя
        Field field = new Field();
        field.show();
    }
}
