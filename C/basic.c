#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j; 
    int a[9] = {11, 22, 53, 47, 51, 61, 17, 86, 15}; 
    for(i = 0; i < 3; i++)
    {
        a[i] = a[i] + 1;
        i++; 
    }
    i--; 
    for(j = 8; j >= 4; j--)
    {
        i = j/2; 
        a[i] = a[i] - 1; 
    }
    printf("%d %d ", i, a[i]); 
    return 0; 
}