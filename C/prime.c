#include <stdio.h>

int main()
{
	int num; 
	printf("Enter the input number: "); 
	scanf("%d", &num); 
	int half; 
	half = num/2; 
	int flag;
	flag = 0;
	
	for (int i = 2; i <= half; i++)
	{
		if (num % i == 0)
		{
			flag++;	
			break;
		}
		else
		{
			continue; 
		} 
	}
	
	if (flag == 0)
	{
		printf("The number is prime"); 
	}
	else
	{
		printf("The number is composite");
	}
	
	return 0;
} 
