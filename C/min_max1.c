#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
    int* maxval = NULL;
    int* minval = NULL;
    char val[MAX_LENGTH];
    int num = atoi(fgets(val, sizeof(val), stdin));

    while (fgets(val, MAX_LENGTH, stdin) != NULL)
    {
        if (maxval = NULL || num > *maxval)
        {
            *maxval = num;
        }

        else if (minval = NULL || num < *minval)
        {
            *minval = num;
        }
        else if (fgets(val, MAX_LENGTH, stdin) == "done")
        {
            break;
        }
    }
    printf("Maximum %d\n", *maxval);
    printf("Minium %d\n", *minval);
}