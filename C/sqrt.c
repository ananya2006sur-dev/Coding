#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long double sqrt(long double b)
{
    long double a;
    (long double)b = ((long double)a)*((long double)a);
    return a;
}

int main()
{
    long double b;
    printf("Enter a number: ");
    scanf("%llf", &b);
    printf("Square root of %llf is %llf\n", b, sqrt(b));
    return 0;
}