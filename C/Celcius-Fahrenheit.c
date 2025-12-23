#include <stdio.h>
int main() /* Fahrenheit-Celsius table */
{
	  int farh;
  	printf("FAHR CELSIUS\n");
  	printf("===============\n");
  	for (farh = 0; farh < 300; farh = farh + 40)
    {
        float celsius = (5.0/9.0) * (farh - 32);
      	printf("%d %.1f\n", farh, celsius);
    }
  	return 0;
}