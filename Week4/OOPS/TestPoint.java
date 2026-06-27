class Point {
    private int x, y;

    // Default constructor
    public Point() {
        this.x = 0;
        this.y = 0;
    }

    // Parameterized constructor
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x)           { this.x = x; }
    public void setY(int y)           { this.y = y; }
    public void setXY(int x, int y)   { this.x = x; this.y = y; }

    public int getX() { return x; }
    public int getY() { return y; }

    @Override
    public String toString() {
        return "Point(" + x + ", " + y + ")";
    }
}

public class TestPoint {
    public static void main(String[] args) {
        System.out.println("\n=== Problem 3: Point Class ===");

        Point p1 = new Point();
        System.out.println("Default constructor  : " + p1);

        Point p2 = new Point(4, 7);
        System.out.println("Parameterized (4,7) : " + p2);

        p1.setX(10);
        System.out.println("After setX(10)      : " + p1);

        p1.setY(20);
        System.out.println("After setY(20)      : " + p1);

        p1.setXY(3, 5);
        System.out.println("After setXY(3,5)    : " + p1);
    }
}