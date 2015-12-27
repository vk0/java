package ex3;

import java.util.Random;

/**
 * Created by igor on 17.05.15.
 */
public class Hippodrome {
    public static void main(String[] args) {
        Horse[] horses = new Horse[10];

        Random random = new Random();

        for (int i = 0; i < horses.length; i++) {
            horses[i] = new Horse();
            horses[i].name = "Буцефал " + i;
            horses[i].age = 1 + random.nextInt(10);
            horses[i].speed = 10 + random.nextInt(100);
            horses[i].isMale = random.nextBoolean();
        }

        for (Horse horse : horses) {
            horse.ride();
        }
    }
}
