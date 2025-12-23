#include <stdio.h>
#define PI 3.14

int main()
{
	float r; 
	printf("Enter the radius of the circle in cms: ");
	scanf("%f", &r);
	float area;
	area = PI*r*r;
	printf("Area of the cirlce is %f in sq.cm", area);
	return 0; 
} 
	