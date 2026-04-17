import java.util.*;

public class RunTimeError
{
	public static void main(String[] args)
	{
		int a = 10; 
		int b = 0;
		
		try
		{
			System.out.println(a/b);
		}
		catch (ArithmeticException e)
		{
			System.out.println("Division by zero not allowed!");
		}
	}
} 