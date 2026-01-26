import java.util.Scanner;

public class Student 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); 
        System.out.printf("Enter the name of the student: "); 
        String name = sc.nextLine(); 
        System.out.printf("Enter the roll number of the student: "); 
        int rollno = sc.nextInt(); 
        System.out.printf("Enter the marks of the student: "); 
        int marks = sc.nextInt(); 
        System.out.printf("Name: %s, Roll No.: %d, Marks: %d\n", name, rollno, marks); 
        sc.close(); 
    }
}
