#include <stdio.h>

int main()
{
	int num1; 
	int num2; 
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	
	if (num1 > num2)
	{
		printf("%d is largest", num1);
	}
	else if (num2 > num1)
	{
		printf("%d is largest", num2);
	}
	else
	{
		printf("Both numbers are equal");
	}
	
	return 0; 
} 