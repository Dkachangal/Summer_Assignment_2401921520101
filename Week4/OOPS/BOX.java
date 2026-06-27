class Box {
    protected double length, breadth;

    public Box() {
        this.length  = 0;
        this.breadth = 0;
    }

    public Box(double length, double breadth) {
        this.length  = length;
        this.breadth = breadth;
    }

    public void setLength(double length)   { this.length  = length; }
    public void setBreadth(double breadth) { this.breadth = breadth; }

    public double area() {
        return length * breadth;
    }

    @Override
    public String toString() {
        return "Box [length=" + length + ", breadth=" + breadth + "]";
    }
}

class Box3D extends Box {
    private double height;

    public Box3D() {
        super();
        this.height = 0;
    }

    public Box3D(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public void setHeight(double height) { this.height = height; }

    // area() → total surface area of the box
    @Override
    public double area() {
        return 2 * (length * breadth + breadth * height + height * length);
    }

    public double volume() {
        return length * breadth * height;
    }

    @Override
    public String toString() {
        return "Box3D [length=" + length + ", breadth=" + breadth + ", height=" + height + "]";
    }
}

public class BOX {
    public static void main(String[] args) {
        System.out.println("\n=== Problem 4: Box & Box3D ===");

        Box b = new Box(8, 5);
        System.out.println(b);
        System.out.println("Area (2D)         = " + b.area());

        System.out.println();

        Box3D b3 = new Box3D(4, 3, 6);
        System.out.println(b3);
        System.out.println("Surface Area (3D) = " + b3.area());
        System.out.println("Volume            = " + b3.volume());

        // Setter demo
        b3.setLength(10);
        b3.setBreadth(5);
        b3.setHeight(2);
        System.out.println("\nAfter setters: " + b3);
        System.out.println("Surface Area (3D) = " + b3.area());
        System.out.println("Volume            = " + b3.volume());
    }
}