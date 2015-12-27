// однострочный коментарий

/* многострочный
комментарий
 */

/**
 * @author Created by igor on 17.05.15.
 *         javadoc
 */

// рецепт, метод, функция, процедура, подпрограмма

public class Kitchen {

    // psvm + Tab
    public static void main(String[] args) {
        System.out.println("main");
        cookBreakfast();
        cookSoup();
    }

    static void cookSoup() {
        // sout + Tab
        // Ctrl-D дублирование строки
        System.out.println("Boil water");
        System.out.println("...");
        System.out.println("done");
    }

    static void cookBreakfast() {
        System.out.println("Breakfast done");
    }
}