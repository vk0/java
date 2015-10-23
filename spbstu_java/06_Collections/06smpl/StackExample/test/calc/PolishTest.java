/*
 * $Id:$
 */

package calc;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Mikhail Glukhikh
 */
public class PolishTest {

    @Test
    public void test1() {
        assertEquals(3.0, Polish.calc("1 2 +"), 1e-10);
    }

    @Test
    public void test2() {
        assertEquals(10.0, Polish.calc("6 -4 -"), 1e-10);
    }

    @Test
    public void test3() {
        assertEquals(3.0, Polish.calc("10 1 2 3 * + -"), 1e-10);
    }

    @Test(expected=IllegalArgumentException.class)
    public void test4() {
        Polish.calc("1 -");
    }
}
