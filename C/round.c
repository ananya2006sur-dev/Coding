#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int round(double x)
{
    return (int)((x + 0.5));
}

int main()
{
    double a;
    printf("Enter a double: ");
    scanf("%lf", &a);
    int b = round(a);
    printf("%lf rounded to nearest integer is %d", a, b);
    return 0;
}