import java.util.Scanner;

public class twoDAgain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of rows: ");
		int m = sc.nextInt();
		int arr[][] = new int[m][]; 
		int cols;
		int num; 
		for(int i = 0; i < m; i++)
		{
			System.out.printf("Enter the number of columns for row %d: ", i);
			cols = sc.nextInt();
			arr[i] = new int[cols];
			for(int j = 0; j < cols; j++)
			{
				System.out.printf("Enter the arr[%d][%d] number: ", i, j);
				num = sc.nextInt(); 
				arr[i][j] = num; 
			}
		}
		System.out.println("The jagged array is as follows: ");
		for(int k = 0; k < m; k++)
		{
			for(int l = 0; l < arr[k].length; l++)
			{
				System.out.print(arr[k][l] + " ");
			}
			System.out.println(); 
		}
		sc.close();
	}
} 