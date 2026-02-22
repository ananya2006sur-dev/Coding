import java.util.Scanner; 

public class runsum 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter the number of elements: "); 
        int n = sc.nextInt(); 
        int[] arr = new int[n]; 
        for(int i = 0; i < n; i++)
        {
            System.out.printf("Enter the %dth element: ", i + 1); 
            arr[i] = sc.nextInt(); 
        }
        System.out.println("The elements of the array are: "); 
        for(int i = 0; i < n; i++)
        {
            System.out.print(arr[i] + " "); 
        }
        System.out.println(); 
        int[] runningsum = new int[n]; 
        runningsum[0] = arr[0]; 
        for(int i = 1; i < n; i++)
        {
            runningsum[i] = runningsum[i - 1] + arr[i]; 
        }
        System.out.println("The running sum of the array is: "); 
        for(int i = 0; i < n; i++)
        {
            System.out.print(runningsum[i] + " "); 
        }
        sc.close();
    }
}
