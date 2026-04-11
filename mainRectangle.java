import java.util.Scanner;

class Rectangle
{
    private float length;
    private float width;
    private String color;

    void setLength(float length)
    {
        this.length = length;
    }

    void setWidth(float width)
    {
        this.width = width;
    }

    void setColor(String color)
    {
        this.color = color;
    }

    float getLength()
    {
        return length; 
    }

    float getWidth()
    {
        return width;
    }

    float getArea()
    {
        return length * width;
    }

    String getColor()
    {
        return color;
    }
}

public class mainRectangle
{
    public static void main(String[] args)
    {
        //Comparing area and color of two rectangles
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the first rectangle: ");
        float length1 = sc.nextFloat();
        System.out.println("Enter the width of the first rectangle: ");
        float width1 = sc.nextFloat();
        System.out.println("Enter the color of the first rectangle: ");
        String color1 = sc.next();
        Rectangle r1 = new Rectangle();
        r1.setLength(length1);
        r1.setWidth(width1);
        r1.setColor(color1);
        System.out.println("Enter the length of the second rectangle: ");
        float length2 = sc.nextFloat();
        System.out.println("Enter the width of the second rectangle: ");
        float width2 = sc.nextFloat();
        System.out.println("Enter the color of the second rectangle: ");
        String color2 = sc.next();
        Rectangle r2 = new Rectangle();
        r2.setLength(length2);
        r2.setWidth(width2);
        r2.setColor(color2);
        if(r1.getArea() > r2.getArea())
        {
            System.out.println("The first rectangle has the greater area");
        }
        else if(r1.getArea() < r2.getArea())
        {
            System.out.println("The second rectangle has the greater area");
        }
        else
        {
            System.out.println("The two rectangles have the same area");
        }
        if(r1.getColor().equals(r2.getColor()))
        {
            System.out.println("The two rectangles have the same color");
        }
        else
        {
            System.out.println("The two rectangles have different colors");
        }
        sc.close();
    }
}