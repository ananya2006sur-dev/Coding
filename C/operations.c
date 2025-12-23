#include <stdio.h>

int main()
{
	int num1;
	int num2;
	printf("Enter value of num1: ");
	scanf("%d", &num1);
	printf("Enter value of num2: ");
	scanf("%d", &num2);
	
	int add;
	add = num1 + num2;
	printf("Sum of the two numbers is %d\n", add);
	
	int diff;
	diff = num1 - num2;
	printf("Difference of the two numbers is %d\n", diff);
	
	int product;
	product = num1*num2;
	printf("Product of the two numbers is %d\n", product);
	
	float div; 
	div = ((float)(num1))/(num2); 
	printf("Division of the two numbers give %f\n", div);
	
	int modulo;
	modulo = num1 % num2; 
	printf("Remainder given by dividing num1 by num2 is %d\n", modulo); 
	
	return 0;
}