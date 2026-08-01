class Student
{
    int rollNo;
    String name; 
    static String college = "Cummins";

    Student()
    {
        this(0, "");
    }
    Student(int rollNo, String name)
    {
        this.rollNo = rollNo;
        this.name = name; 
    }

    void display()
    {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("College: " + college);  
        System.out.println();
    }
}

public class TestStudent
{
    public static void main(String[] args)
    {
        Student s1 = new Student(101, "Ananya");
        Student s2 = new Student(102, "Rahul");
        s1.display();
        s2.display();
    }
}