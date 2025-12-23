#include <stdio.h>

int main()
{
 double a, b, c, sum;
 printf("Input three floats:");
 scanf("%lf%lf%lf", &a, &b, &c);
 printf("a = %lf b = %lf c = %lf\n", a, b);
 sum = a + b + c;
 printf("sum = %lf\n\n", sum);
}