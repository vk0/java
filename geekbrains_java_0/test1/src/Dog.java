/**
 * Created by igor on 17.05.15.
 */
public class Dog {
    public static void main(String[] args) {
        String s;
        s = aport("Косточка", 20);
        System.out.println(s);
    }

    static String aport(String it, int amount) {
        String result;
        result = "Пожёванная " + it + ", количество " + amount;
        return result; // поместить в стек
    }
}

// Stack

// |             |
// |             |
// |             |
// |             |
// _____
