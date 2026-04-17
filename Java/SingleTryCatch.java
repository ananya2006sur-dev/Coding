import java.util.*;

public class SingleTryCatch
{
	public static void main(String[] args)
	{
		int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		try
		{
			System.out.println(a[6]); 
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Array Index Error");
		}
	}
} 
		