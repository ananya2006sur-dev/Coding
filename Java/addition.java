import java.util.Scanner; 

public class addition
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("Enter the first number: "); 
		int num1 = sc.nextInt();
		System.out.printf("Enter the second number: "); 
		int num2 = sc.nextInt(); 
		int result = num1 + num2; 
		System.out.printf("Result: " + result); 
		sc.close(); 
	}
} 
