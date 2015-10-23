/*
 * $Id:$
 */

package tests;

import java.util.Arrays;
import java.util.Calendar;
import java.util.Random;
import junitsample.Rational;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Eugene V. Pychkine
 * @author Mikhail I. Glukhikh
 */
public class RationalJUnitTest {

    Rational val1;
    Rational val2;
    static final Random rand;
    static {
        rand = new Random();
        rand.setSeed(Calendar.getInstance().getTimeInMillis());
    }

    public RationalJUnitTest() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }

    @Before
    public void setUp() {
        val1 = new Rational(1,2);
        val2 = new Rational(-1, 3);
    }

    @After
    public void tearDown() {
    }

    @Test(expected=ArithmeticException.class)
    public void CreateTest1() {
        new Rational( 0, 0 );
    }

    @Test
    public void CreateTest2() {
        new Rational( 0, -1 );
    }

    @Test
    public void AddTest() {
        Rational res = val1.add(val2);
        assertTrue(res.equals(new Rational(1,6)));
    }

    @Test
    public void SubTest() {
        Rational res = val1.sub(val2);
        assertTrue(res.equals(new Rational(5,6)));
    }

    @Test
    public void EqualsTest() {
        Rational x = new Rational(1,2);
        Rational y = new Rational(5,10);
        assertTrue(x.equals(y));
        assertTrue(x.compareTo(y)==0);
    }

    @Test
    public void CompareTest() {
        assertTrue(val1.compareTo(val2) > 0);
        assertTrue(val2.compareTo(val1) < 0);
    }

    @Test
    public void sortTest() {
        final Rational[] arr = new Rational[10];
        for (int i=0; i<10; i++)
            arr[i] = new Rational(rand.nextInt(200)-100, 1+rand.nextInt(100));
        Arrays.sort(arr);
        for (int i=0; i<9; i++)
            assertTrue(arr[i+1].compareTo(arr[i]) > 0);
        for (Rational r: arr)
            System.out.println(r);
    }

    @Test
    public void cloneTest() {
        final Rational r = new Rational(rand.nextInt(200)-100, 1+rand.nextInt(100));
        final Rational result = r.clone();
        assertNotSame(r, result);
        assertEquals(r, result);
    }
}