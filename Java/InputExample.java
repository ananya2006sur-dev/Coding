import java.util.Scanner; 

public class InputExample 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 

        System.out.printf("Enter your name: ");
        String name = sc.nextLine(); 

        System.out.printf("Enter your age: ");
        int age = sc.nextInt(); 

        System.out.printf("Name: " + name + ", age: " + age); 
        sc.close(); 
    }
}
