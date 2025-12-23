#include <stdio.h>

int main()
{
	int num;
	printf("Enter the value of n for which you want to find the sum of first n natural numbers: ");
	scanf("%d", &num);
	int sum; 
	sum = 0; 
	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("Sum of first %d natural numbers is %d", num, sum); 
	return 0;
} 