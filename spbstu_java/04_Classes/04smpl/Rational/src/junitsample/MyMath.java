/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package junitsample;

/**
 *
 * @author Eugene
 */
public class MyMath {
    public static int gcd( int a, int b ) {
        a = Math.abs(a);
        b = Math.abs(b);

        while( a != b ) {
            if( a < b ) b-=a;
            else        a-=b;
        }
        return a;
    }
}
