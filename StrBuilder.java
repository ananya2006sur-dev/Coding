import java.util.Scanner; 

public class StrBuilder 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a name: ");
        String str = sc.next(); 
        StringBuilder sb1 = new StringBuilder(str); 
        StringBuilder sb2 = new StringBuilder(str); 
        sb1.reverse();
        if(sb1.toString().equalsIgnoreCase(sb2.toString()))
        {
            System.out.println("The name is a palindrome");
        }
        else
        {
            System.out.println("The name is not a palindrome");
        }
        sc.close();
    }
}
