/**
 * Created by igor on 17.05.15.
 */
public class Main4Inc {
    public static void main(String[] args) {
        int i;
        i = 0;
        int a2 = ++i + i++;

        i = 0;
        int a;
        i = i + 1;
        a = i;
        a = a + i;
        i = i + 1;
        System.out.println(a2);
        System.out.println(a);

        i = 0;
        a = 0;
        int a3 = i++ + ++i;

        i = 0;
        i = i + 1;
        i = i + 1;
        a = a + i;
        System.out.println(a3);
        System.out.println(a);
    }
}
