/**
 * Created by igor on 17.05.15.
 */
public class Main6MultTable {
    public static void main(String[] args) {
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
//                System.out.println(i + " * " + j + " == " + i * j);
                //sout
//                System.out.print(j + " * " + i + " == " + i * j + "\t\t");
                //souf
                System.out.printf("%d * %d == %d\t\t", j, i, i * j);
            }
            System.out.println();
        }

        System.out.printf("число %d, строка %s, дробное %.1f", 10, "java", 22.1234);
    }
}
