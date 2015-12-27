package ex2_static;

import java.util.Random;

/**
 * Created by igor on 24.05.15.
 */
public class Point {
    private int x;
    private int y;

    public Point() {
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public static Point getRandomPoint() {
        Random random = new Random();
        return new Point(random.nextInt(10), random.nextInt(10));
    }
}
