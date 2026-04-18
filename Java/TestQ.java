class Quadrilateral
{
    float side1; 
    float side2;
    float side3;
    float side4;

    Quadrilateral()
    {
        this(0, 0, 0, 0);
    }

    Quadrilateral(float side1, float side2, float side3, float side4)
    {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
        this.side4 = side4;
    }

    void display()
    {
        System.out.println("Side 1: " + side1);
        System.out.println("Side 2: " + side2);
        System.out.println("Side 3: " + side3);
        System.out.println("Side 4: " + side4);
    }
}

class Parallelogram extends Quadrilateral
{

    Parallelogram()
    {
        this(0, 0);
    }

    Parallelogram(float side1, float side2)
    {
        super(side1, side2, side1, side2);
    }

    void display()
    {
        System.out.println("Side1: " + side1);
        System.out.println("Side2: " + side2);
    }
}

class Trapezium extends Quadrilateral
{

    Trapezium()
    {
        this(0, 0, 0, 0);
    }

    Trapezium(float base1, float base2, float slant1, float slant2)
    {
        super(base1, base2, slant1, slant2);
    }
}

class Rectangle extends Parallelogram
{
    Rectangle()
    {
        this(0, 0);
    }

    Rectangle(float length, float width)
    {
        super(length, width);

    }
}

class Square extends Rectangle
{

    Square()
    {
        this(0);
    }

    Square(float side)
    {
        super(side, side);
    }

    void display()
    {
        System.out.println("Side: " + this.side1);
    }
}

public class TestQ
{
    public static void main(String[] args)
    {
        Quadrilateral q = new Quadrilateral(1, 2, 3, 4);
        q.display();
        Parallelogram p = new Parallelogram(5, 3);
        p.display();
        Trapezium t = new Trapezium(4, 5, 6, 7);
        t.display();
        Rectangle r = new Rectangle(7, 4);
        r.display();
        Square s = new Square(8);
        s.display();
    }
}