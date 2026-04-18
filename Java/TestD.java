class Animal
{
    void eat()
    {
        System.out.println("Eating");
    }
}

interface Flyable
{
    void fly();
}

interface Swimmable
{
    void swim();
}

class Duck extends Animal implements Flyable, Swimmable
{
    public void fly()
    {
        System.out.println("Duck is flying");
    }

    public void swim()
    {
        System.out.println("Duck is swimming"); 
    }
}

public class TestD
{
    public static void main(String[] args) 
    {
        Duck d = new Duck();
        d.eat(); 
        d.fly();
        d.swim();
    }
}