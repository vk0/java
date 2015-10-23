/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package junitsample;

/**
 *
 * @author Eugene
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Rational val1 = new Rational( 1, 2 );
        printRational(val1);
        Rational val2 = new Rational( -1, 3 );
        printRational(val2);
        val1.add(val2);
        printRational(val1);
    }

    static void printRational( Rational val ) {
        System.out.println(val);
    }
}
