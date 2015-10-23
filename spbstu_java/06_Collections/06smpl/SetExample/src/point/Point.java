/*
 * $Id:$
 */

package point;

/**
 * Реализация объекта "точка"
 *
 * @author Mikhail Glukhikh
 */
public class Point implements Cloneable {

    private double x;

    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point moveTo(double x, double y) {
        this.x = x;
        this.y = y;
        return this;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    @Override
    public Point clone() {
        try {
            return (Point)super.clone();
        } catch (CloneNotSupportedException ex) {
            throw new AssertionError(ex.getMessage());
        }
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append("(");
        sb.append(x);
        sb.append(",");
        sb.append(y);
        sb.append(")");
        return sb.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this==obj)
            return true;
        if (obj instanceof Point) {
            final Point p = (Point)obj;
            return x==p.x && y==p.y;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 47 * hash + (int) (Double.doubleToLongBits(this.x) ^ (Double.doubleToLongBits(this.x) >>> 32));
        hash = 47 * hash + (int) (Double.doubleToLongBits(this.y) ^ (Double.doubleToLongBits(this.y) >>> 32));
        return hash;
    }
}
