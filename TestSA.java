interface Shape
{
    void draw();

    default void display()
    {
        System.out.println("This is a shape");
    }

    static void show()
    {
        System.out.println("This is a static method");
    }
}

class Circle implements Shape   
{
    public void draw()
    {
        System.out.println("Drawing a circle");
    }
}

public class TestSA
{
    public static void main(String[] args)
    {
        Circle c = new Circle();
        c.draw();
        c.display();
        Shape.show();
    }
}
