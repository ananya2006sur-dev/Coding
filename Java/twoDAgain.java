import java.util.Scanner;

public class twoDAgain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of rows: ");
		int rows = sc.nextInt();
		int cols; 
		int[][] arr = new int[rows][]; 
		for(int i = 0; i < rows; i++)
		{
			System.out.print("Enter the number of columns for row " + i + ": ");
			cols = sc.nextInt();
			arr[i] = new int[cols]; 
			for(int j = 0; j < cols; j++)
			{
				System.out.print("Enter the element at row " + i + " and column " + j + ": ");
				arr[i][j] = sc.nextInt();
			}
		}
		System.out.println("The jagged array is as follows: ");
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < arr[i].length; j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		sc.close(); 
	}
}