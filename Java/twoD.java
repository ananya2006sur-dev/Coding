import java.util.Scanner;

public class twoD
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); 
		System.out.print("Enter the no. of rows: ");
		int m = sc.nextInt();
		System.out.print("Enter the no. of columns: "); 
		int n = sc.nextInt();
		int[][] arr = new int[m][n];
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.printf("Enter the element arr[%d][%d]: ", i, j);
				arr[i][j] = sc.nextInt();
			}
		}
		System.out.println("Matrix: ");
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.print(arr[i][j] + " "); 
			}
			System.out.printf("\n");
		}
		int bottom = m - 1; 
		int top = 0; 
		int right = n - 1;
		int left = 0; 
		int i, j;
		System.out.println("Spiral order: ");
		while(top <= bottom && left <= right)
		{
			i = top; 
			j = left - 1; 
			while(j < right)
			{
				j++;
				System.out.print(arr[i][j] + " ");
			}
			top++;
			while(i < bottom)
			{
				i++;
				System.out.print(arr[i][j] + " ");
			}
			right--; 
			if(top <= bottom)
			{
				while(j > left)
				{
					j--; 
					System.out.print(arr[i][j] + " ");
				}
				bottom--;
			}
			if(left <= right)
			{
				while(i > top)
				{
					i--;
					System.out.print(arr[i][j] + " ");
				}
				left++;
			}
		sc.close(); 
	}
	}
}
 