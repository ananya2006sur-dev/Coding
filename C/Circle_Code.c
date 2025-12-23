/* Calculating area of a circle 
    with given radius
    Author - Ananya
*/


#include <stdio.h>
#define PI 3.14159 

int main()
{
    double area, radius;
    printf("Input the radius:\n");
    scanf("%lf", &radius);
    area = PI*radius*radius;
    printf("Area = %lf", area);
    return 0;
}

