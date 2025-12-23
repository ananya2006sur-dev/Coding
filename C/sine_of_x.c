/*Calculating sine of an angle x in radians where, 0 < x < 1*/

#include <stdio.h> 
#include <math.h>
#define PI 3.14159

int main()
{ 
	double i,s,c;
	for (i = 0; i < 1; i = i + 0.1); 
	
		s = sin(i);
		c = cos(i);
		printf("The value of sin(%lf) is %lf\n",i,s);
		printf("The value of cos(%lf) is %lf\n",i,c);
		return 0;
	
}	

