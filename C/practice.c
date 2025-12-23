#include <stdio.h>
#include <string.h>

int factorial(unsigned int n)
{
    if (n == 1)
    {
        return 1; 
    }
    return n * factorial(n - 1); 
}

int main()
{
    unsigned int num; 
    printf("Enter a positive integer: ");
    scanf("%u", &num);
    printf("Factorial of %u = %u\n", num, factorial(num));
    return 0;
}