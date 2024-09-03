class Shape {
    void draw() {
        System.out.println("Drawing a shape");
    }
    double calculateArea() {
        return 0.0;
    }
}

class Circle extends Shape {
    double radius;
    Circle(double radius) {
        this.radius = radius;
    }
    @Override
    void draw() {
        System.out.println("Drawing a circle");
    }

    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Cylinder extends Circle {
    double height;

    Cylinder(double radius, double height) {
        super(radius);
        this.height = height;
    }
    @Override
    void draw() {
        System.out.println("Drawing a cylinder");
    }
    @Override
    double calculateArea() {
        return 2 * Math.PI * radius * (radius + height);
    }
}

public class Geometry_Q8 {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        circle.draw();
        System.out.println("Area of the circle: " + circle.calculateArea());

        Cylinder cylinder = new Cylinder(5, 10);
        cylinder.draw();
        System.out.println("Total surface area of the cylinder: " + cylinder.calculateArea());
    }
}
