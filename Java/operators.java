import java.util.Scanner; 

public class operators
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the moisture level in %: "); 
		int M = sc.nextInt(); //moisture 
		
		System.out.print("Enter the temperature in degree celcius: "); 
		int T = sc.nextInt(); //temperature
		
		int R = 2*M + T; //risk score
		
		int C = R % 3; //risk category
		
		M = M + 1; //calibration moisture
		
		T = T - 1; //calibration temperature
		
		int SM = 1; //moisture sensor flag
		
		int ST = 2; //temperature sensor flag
		
		int S = SM ^ ST; //system status
		
		int F = SM & ST; //fault check
		
		
		
		String final_status = (M > 70 && T > 35) ? "UNSAFE" : ((M > 70 || T > 35) ? "WARNING" : "SAFE"); 
		
		System.out.printf("Calibrated Moisture = %d, Calibrated Temperature = %d\n", M, T); 
		
		System.out.printf("Risk Score = %d, Risk Category = %d, System Status = %d, Fault Check = %d\n", R, C, S, F); 
		
		System.out.printf("Final Status = %s\n", final_status); 
		
		sc.close(); 
	}
}
		
	