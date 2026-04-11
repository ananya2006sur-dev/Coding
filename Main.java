import java.util.*;

class Animal 
{
    int legs;
    String name;
    String color;

    Animal() 
    {
        System.out.println("Inside default Animal constructor");
    }

    Animal(int legs, String name, String color) 
    {
        System.out.println("Inside parameterized Animal constructor");
        this.legs = legs;
        this.name = name;
        this.color = color;
    }

    void display() 
    {
        System.out.println("Animal name: " + name);
        System.out.println("Animal color: " + color);
        System.out.println("Animal legs: " + legs);
    }

    void sound() 
    {
        System.out.println("Make Sound");
    }

    void run() 
    {
        System.out.println("Run");
    }
}

class Dog extends Animal 
{
    Dog(int legs, String name, String color) 
    {
        super(legs, name, color); // calling the constructor of the parent class using super keyword
        System.out.println("Inside Dog constructor");
    }

    @Override // Overriding on display method of the parent class
    void display() 
    {
        System.out.println("Dog name: " + name);
        System.out.println("Dog color: " + color);
        System.out.println("Dog legs: " + legs);
    }

    @Override // Overriding on sound method of the parent class
    void sound()
    {
        super.sound();
        System.out.println("Bark");
    }

    @Override // Overriding on run method of the parent class
    void run()
    {
        super.run();
        System.out.println("Run at average speed of 10 km/h");
    }
}

class Cat extends Animal
{
    Cat(int legs, String name, String color)
    {
        super(legs, name, color);
    }

    @Override
    void display()
    {
        super.display();
        System.out.println("Cat name: " + name);
        System.out.println("Cat color: " + color);
        System.out.println("Cat legs: " + legs);
    }

    @Override
    void sound()
    {
        super.sound();
        System.out.println("Meow");
    }

    @Override
    void run()
    {
        super.run();
        System.out.println("Run at average speed of 5 km/h");
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name of the dog: ");
        String name1 = sc.nextLine();

        System.out.print("Enter color of the dog: ");
        String color1 = sc.nextLine();

        System.out.print("Enter name of the cat: ");
        String name2 = sc.nextLine();

        System.out.print("Enter color of the cat: ");
        String color2 = sc.nextLine();

        Dog d = new Dog(4, name1, color1);
        Cat c = new Cat(4, name2, color2);

        d.display();
        d.sound();
        d.run();
        c.display();
        c.sound();
        c.run();

        sc.close();
    }
}