import java.util.Scanner;

public class vote
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("Enter your age: "); 
		int age = sc.nextInt(); 
		if (age < 18)
			System.out.printf("Not eligible to vote"); 
		else
			System.out.printf("Eligible to vote"); 
		sc.close(); 
	}
} 