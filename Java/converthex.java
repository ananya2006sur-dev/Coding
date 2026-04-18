import java.util.Scanner;

public class converthex
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        if (!sc.hasNextInt())
        {
            System.out.println("Invalid input. Please enter a valid integer.");
            sc.close();
            return;
        }
        int n = sc.nextInt();
        System.out.println("Hexadecimal: " + Integer.toHexString(n));
        sc.close();
    }
}
