#include <stdio.h>

int main()
{
     int i, sum = 0, n = 5;
     for (i = 1; i < n; i++)
     {
          sum = sum + i;
          printf("sum = %d , i = %d\n", sum, i);
     }
     return 0;
}