package ex2_static;

/**
 * Created by igor on 24.05.15.
 */
public class SuperField {
    private static SuperField ourInstance = new SuperField();

    public static SuperField getInstance() {
        return ourInstance;
    }

    private SuperField() {
    }
}
