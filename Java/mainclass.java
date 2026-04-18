import java.util.Scanner;

class AreaCalculator
{
	double findArea(double length, double breadth)
	{
		return (length * breadth);
	}
	
	double findArea(double side)
	{
		return (side * side);
	}
	
	double findArea(float base, float height)
	{
		return (0.5 * base * height);
	}
	
	double findArea(float radius)
	{
		return (3.14159 * radius * radius);
	}
}

public class mainclass
{
public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		AreaCalculator a = new AreaCalculator(); 
		int choice = 0;
		while(choice != 5)
		{
			System.out.println("Enter choice:\n1.Rectangle\n2.Sqaure\n3.Triangle\n4.Circle\n5.Exit");
			choice = sc.nextInt();
			switch(choice)
			{
				case 1:
				System.out.print("Enter the length and breadth of the rectangle: ");
				double length = sc.nextDouble();
				double breadth = sc.nextDouble();
				System.out.println("The area of the rectangle is: " + a.findArea(length, breadth)); 
				break;
			
				case 2:
				System.out.print("Enter the side of the square: ");
				double side = sc.nextDouble();
				System.out.println("The area of the square is: " + a.findArea(side));
				break;
			
				case 3:
				System.out.print("Enter the base and heigth of the triangle: ");
				float base = sc.nextFloat();
				float height = sc.nextFloat();
				System.out.println("The area of the triangle is: " + a.findArea(base, height));
				break; 
			
				case 4:
				System.out.print("Enter radius of the circle: ");
				float radius = sc.nextFloat();
				System.out.println("The area of the circle is: " + a.findArea(radius));
				break; 
				
				case 5:
				System.out.print("Exiting"); 
			}
		}
        sc.close();
	}
}