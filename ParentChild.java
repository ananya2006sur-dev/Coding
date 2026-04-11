class Parent 
{
    private int x;

    Parent(int x)
    {
        this.x = x;
    }

    void display()
    {
        System.out.println("The value of x is " + x);
    }

    int getX()
    {
        return this.x;
    }
}

class Child extends Parent
{
    Child(int x)
    {
        super(x);
    }

    void display()
    {
        System.out.println("The value of x is " + this.getX());
    }
}

public class ParentChild
{
    public static void main(String[] args)
    {
        Child c = new Child(10);
        c.display();
    }
}