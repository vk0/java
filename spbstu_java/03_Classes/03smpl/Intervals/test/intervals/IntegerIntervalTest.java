/*
 * $Id:$
 */

package intervals;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 * Тесты интервала целых значений
 * @author Mikhail Glukhikh 
 */
public class IntegerIntervalTest {

    @Test
    public void testAdd() {
        final IntegerInterval var1 = new IntegerInterval(-6, 4);
        final IntegerInterval var2 = new IntegerInterval(2, 5);
        final IntegerInterval res = new IntegerInterval(-4, 9);
        assertEquals(res, var1.add(var2));
        assertEquals(res, var2.add(var1));
    }

    @Test
    public void testSub() {
        final IntegerInterval var1 = new IntegerInterval(-6, 4);
        final IntegerInterval var2 = new IntegerInterval(2, 5);
        final IntegerInterval res = new IntegerInterval(-11, 2);
        assertEquals(res, var1.sub(var2));
        assertEquals(res, var2.sub(var1));
    }

    @Test
    public void testClone() {
        try {
            final IntegerInterval var = new IntegerInterval(10, 20);
            final IntegerInterval res = var.clone();
            assertEquals(var, res);
            assertNotSame(var, res);
        } catch (CloneNotSupportedException ex) {
            fail("Клонирование не поддерживается: " + ex.getMessage());
        }
    }
    
    @Test
    public void testDisj() {
        final IntegerInterval var1 = new IntegerInterval(-9, 8);
        final IntegerInterval var2 = new IntegerInterval(2, 10);
        final IntegerInterval res = new IntegerInterval(-9, 10);
        assertEquals(res, var1.disj(var2));
        assertEquals(res, var2.disj(var1));
    }

    @Test
    public void testConj1() {
        final IntegerInterval var1 = new IntegerInterval(-9, 8);
        final IntegerInterval var2 = new IntegerInterval(2, 10);
        final IntegerInterval res = new IntegerInterval(2, 8);
        assertEquals(res, var1.conj(var2));
        assertEquals(res, var2.conj(var1));
    }

    @Test
    public void testConj2() {
        try {
            final IntegerInterval var1 = new IntegerInterval(1, 2);
            final IntegerInterval var2 = new IntegerInterval(3, 4);
            var1.conj(var2);
            fail("Должно было произойти исключение");
        } catch (IllegalArgumentException ex) {
        }
    }

    @Test
    public void testInv() {
        final IntegerInterval var = new IntegerInterval(-5, 0);
        assertEquals(new IntegerInterval(0, 5), var.inv());
    }
}

