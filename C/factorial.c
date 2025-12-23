#include <stdio.h>

int factorial(int n) 
{
    int factorial = 1; 
    for (int i = n; i > 0; i--)
    { 
        factorial = factorial * i; 
    }
    return factorial;
}

int main()
{
    int a;
    printf("Enter the number whose factorial is to be calculated: ");
    scanf("%d", &a);
    printf("The factorial of %d is %d\n", a, factorial(a));
    return 0;
}