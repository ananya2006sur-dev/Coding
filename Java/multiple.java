import java.util.Scanner; 

public class multiple
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("Enter your name: "); 
		String name = sc.next(); 
		System.out.printf("Enter the number of times you want to display your name: "); 
		int times = sc.nextInt(); 
		for(int i = 0; i < times; i++)
		{
			System.out.printf("%s\n", name); 
			if (i == times - 1)
			{
				System.out.printf("%s", name);
			}
		}
		sc.close(); 
	}
}