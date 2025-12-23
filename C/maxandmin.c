#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int integers[10];
    int max;
    int min;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        integers[i] = rand() % 100;
        printf("%d%c", integers[i], ' ');
        
        if (i == 9)
        {
            printf("%c", '\n');
        }
    }
    for (int j = 0; j < 10; j++)
    {
        if (j == 0)
        {
            max = integers[j];
            min = integers[j];
        }
        else if (integers[j] > max)
        {
            max = integers[j];
        }
        else if (integers[j] < min)
        {
            min = integers[j];
        }
    }
    printf("Maximum number is: %d\n", max);
    printf("Minimum number is: %d\n", min);
    return 0;
}


