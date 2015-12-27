package ex1;

/**
 * Created by igor on 17.05.15.
 */
public class Cat {
    // Характеристики (состояние), свойства, поля
    int age;
    String name;
    double weight;
    boolean isMale;
    // Alt-Enter -- попросить ИДЕЮ предложить варианты исправления ошибки
    Tail tail = new Tail(); // композиция
    Talisman talisman; // агрегация

    // Методы (поведение)
    void voice() {
        System.out.println("myau");
    }

    void sleep() {
        System.out.println("hrrrr");
    }

    //TODO тестовая заметка
    void about() {
        String s = "Cat{" +
                "age=" + age +
                ", name=" + name +
                ", weight=" + weight +
                ", isMale=" + isMale +
                ", tail=" + tail +
                ", talisman=" + talisman +
                '}';
        System.out.println(s);
    }

    // Конструкторы
//    Cat() {
//        System.out.println("вызвали пустой конструктор");
//    }

    Cat() {
    }

    // Alt-ins, Ctrl-Enter

    public Cat(int age, String name, boolean isMale) {
        // Dima:аргумент метода скрывает поле класса
        this.age = age;
        this.name = name;
        this.isMale = isMale;
    }
}
