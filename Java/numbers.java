import java.util.Scanner; 

public class numbers
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("For first n natural numbers, enter n: ");
		int n = sc.nextInt(); 
		for(int i = 1; i <= n; i++)
		{ 
			if (i == n)
			{
				System.out.print(i); 
				break; 
			}
			System.out.println(i);
		}
        sc.close(); 
	}
}