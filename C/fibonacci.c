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
    int a;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {
        printf("%d\n", fibonacci(i));
    }
    return 0;
}