/*
 * $Id:$
 */

package intervals;

/**
 *
 * @author Mikhail Glukhikh
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        final IntegerInterval var1 = new IntegerInterval(1000000000, 1100000000);
        System.out.println(var1.add(var1));
    }
}
