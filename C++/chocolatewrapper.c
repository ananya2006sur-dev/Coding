#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chocolateFeast(int n, int c, int m)
{
    int initial_chocolates = n / c;
    int wrapper_count = initial_chocolates;
    int chocolates_eaten = initial_chocolates;
    while (wrapper_count >= m)
    {
        for (int i = wrapper_count; i >= 0; i--)
        {
            if (i % m == 0)
            {
                chocolates_eaten = chocolates_eaten + (i/m);
                wrapper_count = wrapper_count - i + i/m;
                break;
            }
        }
    }
    return chocolates_eaten;
}

int main()
{
    printf("%d\n", chocolateFeast(15, 3, 2));
    return 0;
}