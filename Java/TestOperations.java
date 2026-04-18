import java.util.Scanner;

class Operations
{
    static int add(int a, int b)
    {
        return a + b;
    }

    static int add(int a, int b, int c)
    {
        return a + b + c;
    }

    static float add(float a, float b)
    {
        return a + b;
    }

    static float add(float a, float b, float c)
    {
        return a + b + c;
    }
}

public class TestOperations
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int num1 = sc.nextInt();
        System.out.println("Enter the second number: ");
        int num2 = sc.nextInt();
        System.out.println("Enter the third number: ");
        int num3 = sc.nextInt();
        System.out.println("The sum of the two integers is: " + Operations.add(num1, num2));
        System.out.println("The sum of the three integers is: " + Operations.add(num1, num2, num3));
        System.out.println("Enter the first float: ");
        float num4 = sc.nextFloat();
        System.out.println("Enter the second float: ");
        float num5 = sc.nextFloat();
        System.out.println("The sum of the two floats is: " + Operations.add(num4, num5));
        System.out.println("Enter the third float: ");
        float num6 = sc.nextFloat();
        System.out.println("The sum of the three floats is: " + Operations.add(num4, num5, num6));
        sc.close();
    }
}
