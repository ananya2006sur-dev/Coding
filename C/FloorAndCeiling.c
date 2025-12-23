#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    printf("Enter a float number: ");
    scanf("%f", &x);
    printf("Floor of %f is %d\n", x, (int)floorf(x));
    printf("Ceiling of %f is %d\n", x, (int)ceilf(x));
    return 0;
}