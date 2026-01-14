import java.util.Scanner; 

public class grade
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.printf("Enter your marks: "); 
		int marks = sc.nextInt(); 
		if (marks < 40 && marks >= 0)
		{
			System.out.printf("Grade: F (Fail)"); 
		}
		else if (marks >= 40 && marks < 50)
		{
			System.out.printf("Grade: C"); 
		}
		else if (marks >= 50 && marks < 60)
		{
			System.out.printf("Grade: B"); 
		}
		else if (marks >= 60 && marks < 70)
		{
			System.out.printf("Grade: B+"); 
		}
		else if (marks >= 70 && marks < 80)
		{
			System.out.printf("Grade: A");
		}
		else if (marks >= 80 && marks < 90)
		{
			System.out.printf("Grade: A+"); 
		}
		else if (marks >= 90 && marks <= 100)
		{
			System.out.printf("Grade: O");
		}
		else
		{
			System.out.printf("Invalid marks"); 
		}
		sc.close();
	}
} 


