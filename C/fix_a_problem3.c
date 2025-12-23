#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
    double interval;
    int i;
    for(i = 0; i < 30; i++)
    {
        interval = i/10.0;
        printf("sin(%lf)=%lf\n", interval, fabs(sin(interval))); /* abs() function gives int value but fabs() function gives float value*/
    }
    printf("\n+++++++\n");
    return 0;
}