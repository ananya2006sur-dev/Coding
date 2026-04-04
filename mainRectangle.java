import java.util.*;

class Rectangle {
    private float length;
    private float width;
    private float area;
    private String color;

    // Setters
    public void setLength(float length) {
        this.length = length;
        calculateArea();
    }

    public void setWidth(float width) {
        this.width = width;
        calculateArea();
    }

    public void setColor(String color) {
        this.color = color;
    }

    // Getters
    public float getArea() {
        return area;
    }

    public String getColor() {
        return color;
    }

    // Calculate area
    private void calculateArea() {
        area = length * width;
    }
}

public class mainRectangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle();

        // Input for Rectangle 1
        System.out.println("Enter details for Rectangle 1:");
        System.out.print("Length: ");
        r1.setLength(sc.nextFloat());

        System.out.print("Width: ");
        r1.setWidth(sc.nextFloat());

        sc.nextLine(); // clear buffer
        System.out.print("Color: ");
        r1.setColor(sc.nextLine());

        // Input for Rectangle 2
        System.out.println("\nEnter details for Rectangle 2:");
        System.out.print("Length: ");
        r2.setLength(sc.nextFloat());

        System.out.print("Width: ");
        r2.setWidth(sc.nextFloat());

        sc.nextLine(); // clear buffer
        System.out.print("Color: ");
        r2.setColor(sc.nextLine());

        // Display areas
        System.out.println("\nRectangle 1 Area: " + r1.getArea());
        System.out.println("Rectangle 2 Area: " + r2.getArea());

        // Compare areas
        if (r1.getArea() == r2.getArea()) {
            System.out.println("Areas are equal");
        } else {
            System.out.println("Areas are not equal");
        }

        // Compare colors
        if (r1.getColor().equalsIgnoreCase(r2.getColor())) {
            System.out.println("Colors are same");
        } else {
            System.out.println("Colors are different");
        }

        sc.close();
    }
}