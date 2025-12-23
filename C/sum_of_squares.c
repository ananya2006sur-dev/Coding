/* Calculating sum of squares of first n natural numbers*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i; 
    int n; 
    int sum = 0; 
    printf("Enter the number of terms: "); 
    scanf("%d", &n); 
    for (i = 1; i <= n; i++) 
    {
        sum = sum + pow(i, 2); 
    }
    printf("The sum of the squares of the first %d natural numbers is %d\n", n, sum); 
    return 0;
}