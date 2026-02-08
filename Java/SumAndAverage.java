import java.util.Scanner; 

public class SumAndAverage
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("Enter how many numbers are there: "); 
		int n = sc.nextInt(); 
		int sum = 0; 
		for(int i = 0; i < n; i++)
		{
			System.out.printf("Enter the number: "); 
			int num = sc.nextInt(); 
			sum = sum + num; 
		}
		float average = ((float)sum)/ n; 
		System.out.printf("Sum = %d, average = %f\n", sum, average); 
		sc.close(); 
	}
}
	