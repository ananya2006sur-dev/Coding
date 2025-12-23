#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int ep = rand() % 1000 + 500;
    printf("%d\n", ep);
    return 0;
}