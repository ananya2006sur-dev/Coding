#include <stdio.h>

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else 
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the number n to get the nth term of the fibonacci series: ");
    scanf("%d", &n);
    printf("The %dth term is : %d\n", n, fibonacci(n));
    return 0;
}