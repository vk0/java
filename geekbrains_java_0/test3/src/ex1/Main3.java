package ex1;

/**
 * Created by igor on 17.05.15.
 */
public class Main3 {
    public static void main(String[] args) {
        // если со стека нет ссылки на объект в куче,
        // а в куче объект указывает на другой объект в кучее -- объект все равно будет уничтоже GC
        new Cat(3, "Tom", false);
        Cat cat1 = new Cat(3, "Tom", true);
        Cat cat2 = new Cat(2, "Murka", false);

        //TODO у меня возник вопрос
        cat1.about();

        Cat tempCat = cat1;

        cat1 = cat2;

        cat1.about();

        tempCat.about();

    }
}
