class Outer {
    void display() {
        System.out.println("I am the Outer class display()");
    }

    class Inner {
        void display() {
            System.out.println("I am the Inner class display()");
        }
    }
}

public class OuterInner {
    public static void main(String[] args) {
        System.out.println("\n=== Problem 2: Outer & Inner Class ===");
        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();
    }
}