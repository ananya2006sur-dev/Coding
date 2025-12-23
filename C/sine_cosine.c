/* A Program to create a table of values for sine and cosine functions*/
#include <stdio.h>
#include <math.h> // has sin() and cos() functions

int main()
{
    printf("Angle   Sine   Cosine\n"); //for the field names of the table
    for (float i = 0; i <= 1.0; i=i+0.1)
    { 
        printf("%f   %lf   %lf\n", i, sin(i), cos(i)); //for the data in the table
    }
    return 0;
}