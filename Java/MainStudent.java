
interface StudentInterface
{
    void learn(); // by default, all methods in an interface are public and abstract

    default public void sleep()
    {
        System.out.println("Student is sleeping for 8 hours");
    }

    static public void study()
    {
        System.out.println("Student is studying");
    }
}

class StudentClass
{
    String name; 
    int age; 
    int grade;
    int rollNo;

    StudentClass()
    {
        this("", 0, 0, 0);
    }

    StudentClass(String name, int age, int grade, int rollNo)
    {
        this.name = name;
        this.age = age;
        this.grade = grade;
        this.rollNo = rollNo;
    }

    void display()
    {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Grade: " + grade);
        System.out.println("Roll No: " + rollNo);
    }
}

class Primary extends StudentClass implements StudentInterface
{
    Primary()
    {
        super(); 
    }

    Primary(String name, int age, int grade, int rollNo)
    {
        super(name, age, grade, rollNo);
    }

    public void learn()
    {
        System.out.println("Primary student is learning addition, subtraction, multiplication, divsion, fractions, decimals");
    }

    public void sleep()
    {
        System.out.println("Primary student is sleeping for 11 hours");
    }
}

class Middle extends StudentClass implements StudentInterface
{
    Middle()
    {
        super();
    }
    
    Middle(String name, int age, int grade, int rollNo)
    {
        super(name, age, grade, rollNo);
    }

    public void learn()
    {
        System.out.println("Middle student is learning algebra, geometry, statistics, probability, ratios, proportions");
    }

    public void sleep()
    {
        System.out.println("Middle student is sleeping for 9 hours");
    }
}

class Secondary extends StudentClass implements StudentInterface
{
    Secondary()
    {
        super();
    }
    
    Secondary(String name, int age, int grade, int rollNo)
    {
        super(name, age, grade, rollNo);
    }

    public void learn()
    {
        System.out.println("Secondary student is learning linear equations, quadratic equations, trigonometry");
    }

    public void sleep()
    {
        System.out.println("Secondary student is sleeping for 7 hours");
    }
}

class Higher extends StudentClass implements StudentInterface
{
    Higher()
    {
        super();
    }
    
    Higher(String name, int age, int grade, int rollNo)
    {
        super(name, age, grade, rollNo);
    }

    public void learn()
    {
        System.out.println("Higher student is learning calculus, differential equations, linear algebra");
    }

    public void sleep()
    {
        System.out.println("Higher student is sleeping for 5 hours");
    }
}

public class MainStudent
{
    public static void main(String[] args)
    {
        Primary p = new Primary("John", 10, 5, 101);
        p.display();
        p.learn();
        p.sleep();

        Middle m = new Middle("Jane", 12, 7, 102);
        m.display();
        m.learn();
        m.sleep();

        Secondary s = new Secondary("Jim", 14, 9, 103);
        s.display();
        s.learn();
        s.sleep();

        Higher h = new Higher("Jill", 16, 11, 104);
        h.display();
        h.learn();
        h.sleep();
    }
}
