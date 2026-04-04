class Student
{
    int rollNo;
    String name;
    static String college = "Cummins College";   // static variable

    // Constructor
    Student(int r, String n)
    {
        rollNo = r;
        name = n;
    }

    // Method to display student information (object passed as parameter)
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

        // Passing objects to method
        s1.display();
        s2.display();
    }
}