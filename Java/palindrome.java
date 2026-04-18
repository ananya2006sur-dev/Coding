import java.util.*;
public class palindrome
{
    public static boolean isPalindrome(String str)
    {
        int len = str.length();
        if(len <= 1)
            return true;
        for(int i = 0; i < len/2; i++)
        {
            if(Character.toLowerCase(str.charAt(i)) != Character.toLowerCase(str.charAt(len - i - 1)))
                return false;
        }
        return true;
    }
	public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while (true) 
        {
            System.out.println("Do you want to check if a string is a palindrome? (y/n)");
            char choice = sc.next().charAt(0);
            sc.nextLine(); // consume newline left after next(); otherwise nextLine() skips input
            if(choice == 'y')
            {
                System.out.println("Enter a string: ");
                String str = sc.nextLine();
                System.out.println("Is " + str + " a palindrome? " + isPalindrome(str));
            }
            else if(choice == 'n')
            {
                System.out.println("Exiting program...");
                break;
            }
            else
            {
                System.out.println("Invalid choice");
            }
        }
        sc.close();
    }
}
