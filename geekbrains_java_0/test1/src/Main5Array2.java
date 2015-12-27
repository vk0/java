import java.util.Arrays;

/**
 * Created by igor on 17.05.15.
 */
public class Main5Array2 {
    public static void main(String[] args) {
        Kitchen kitchen;
        Dog dog;
        Main5Array2 m;

        int a;
        a = 10;

        int[] stable; // так будет называеться наше стойло, но пока оно не построено
//        stable = {2, 3, 4}; // так не работает
        stable = new int[100]; // построили стойло для лошадей на 100 персон

        System.out.println(Integer.valueOf(stable[0]));
//        for (int number : stable) {
//            System.out.println(number);
//        }
//        stable[3] = 55;
        System.out.println(Arrays.toString(stable));

        String[] smth = {"10", "hello", "30", "привет"};

    }
}
