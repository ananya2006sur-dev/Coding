#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    for (int i = 1; i < 11; i++)
    {
        int x = rand() % 100;
        printf("%d ", x);
    }
    return 0;
}