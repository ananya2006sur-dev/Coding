/*Converting data type of 'Volume of Sphere' from int to double*/

#include <stdio.h>
#define PI 3.14159

int main()
{
    double radius;
    printf("Enter radius:");
    scanf("%lf", &radius);
    printf("volume is : %lf\n\n", (4.0*PI*radius*radius*radius)/3.0);
    return 0;
}