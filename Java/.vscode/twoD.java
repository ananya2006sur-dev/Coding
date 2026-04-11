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
		int k = 1;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				arr[i][j] = k;
				k++;
			}
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.print(arr[i][j] + " "); 
			}
			System.out.printf("\n");
		}
		int bottom = m; 
		int top = 0; 
		int right = n;
		int left = 0; 
		int i, j;
		while(top < bottom && left < right)
		{
			i = top; 
			j = left - 1; 
			while(j < right - 1)
			{
				j++; 
				System.out.print(arr[i][j] + " ");
			} 
			top++; 
			while(i < bottom - 1)
			{
				i++; 
				System.out.print(arr[i][j] + " ");
			}
			right--;
			while(j > left)
			{
				j--; 
				System.out.print(arr[i][j] + " ");
			}
			bottom--; 
			while(i > top)
			{
				i--; 
				System.out.print(arr[i][j] + " ");
			}
			left++;
		}
		
	}
} 