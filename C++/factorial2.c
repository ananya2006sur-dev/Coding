#include <stdio.h>

int factorial(int n)
{
    int fact = n;
    if (n == 1)
    {
        return 1;
    }
    if (n > 0)
    {
        fact = n * factorial(n - 1);
    }
    return fact;
}

int main()
{
    int n;
    printf("Enter the number whose factorial is to be calculated : ");
    scanf("%d", &n);
    printf("Factorial is: %d\n", factorial(n));
    return 0;
}