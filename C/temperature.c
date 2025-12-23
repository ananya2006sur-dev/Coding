#include <stdio.h>

int main()
{
int c, f;
printf("Enter temperature in Celcius: ");
scanf("%d", &c);
f = 1.8*c + 32;
printf("Temperature in farhenheit = %d", f);
return 0;

}