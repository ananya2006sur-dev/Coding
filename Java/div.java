import java.util.Scanner;

public class div
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter the last number: "); 
        int N = sc.nextInt(); 
        for(int i = 1; i <= N; i++)
        {
            if(i % 3 == 0 && i % 4 == 0)
            {
                System.out.print("X "); 
            }
            else if(i % 3 == 0)
            {
                System.out.print("A "); 
            }
            else if(i % 4 == 0)
            {
                System.out.print("B "); 
            }
            else 
            {
                System.out.print(i + " "); 
            }
        }
        sc.close(); 
    }
}
