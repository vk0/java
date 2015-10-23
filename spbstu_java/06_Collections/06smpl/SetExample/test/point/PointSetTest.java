/*
 * $Id:$
 */

package point;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Mikhail Glukhikh
 */
public class PointSetTest {

    private static void assertContains(final PointSet set, final Point p) {
        //assertTrue(set.contains(p));
        assertTrue("Множество " + set + " не содержит " + p, set.contains(p));
    }

    @Test
    public void testContains() {
        final PointSet set = new PointSet();
        final Point p = new Point(1.0, 2.0);
        set.add(p);
        assertContains(set, p);
        final Point c = p.clone();
        assertContains(set, c);
        p.moveTo(2.0, 1.0);
        assertContains(set, p);
//        assertContains(set, c);
    }
}
