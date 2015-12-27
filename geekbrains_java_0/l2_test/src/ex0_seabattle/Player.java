package ex0_seabattle;

import java.util.Scanner;

/**
 * Created by igor on 17.05.15.
 */
public class Player {
    int getShoot() {
        System.out.println("Куда стрелять?");
        Scanner scanner = new Scanner(System.in);
        String s;
        s = scanner.nextLine();
        System.out.printf("Вы ввели: %s\n", s);
        int shoot = Integer.parseInt(s);
        return shoot;
    }
}
