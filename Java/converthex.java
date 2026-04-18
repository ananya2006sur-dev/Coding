import java.util.Scanner;

public class converthex
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an integer: ");
        int n = sc.nextInt();
        String hex = Integer.toHexString(n).toUpperCase();
        System.out.println("Hexadecimal: " + hex);
        sc.close();
    }
}
