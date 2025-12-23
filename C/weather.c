#include <stdio.h>

int main()
{
    int outside, weather;
    printf("Enter if outisde 1 true 0 false");
    scanf("%d", &outside);
    printf("Enter if rain 1 true 0 false");
    scanf("%d", &weather);
    if (outside && weather)
      { 
         printf("Please use an umbrella");
      }
    else 
    {
       printf("Dress normally");
    }
      return 0;
}