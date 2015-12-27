package ex1_arraylist;

import java.util.ArrayList;

/**
 * Created by igor on 24.05.15.
 */
public class Main3 {
    public static void main(String[] args) {
        int[] ints = new int[10];

        // 100 (4)
        // 010 (2)
        ArrayList<Ship> list = new ArrayList<Ship>();
//        list.add(123);
//        list.add("hello");
//        list.add(12);
//        list.add("hello");
//        list.add(new Ship());
//        list.add(8685.0);

        list.remove("hello");

        System.out.println(list);

        for (Object o : list) {
            System.out.println(o);
        }
    }
}
