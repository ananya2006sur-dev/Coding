#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    int x = 10000;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++)
    {
        sum = sum + (n / x);
        n = n % x;
        x = x / 10;
    }
    printf("%d", sum);
    return 0;
}