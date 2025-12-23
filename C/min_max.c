#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
    int* pmaxval = NULL;
    int* pminval = NULL; 
    int maxval = 0;
    int minval = 0;
    char val[MAX_LENGTH];
    int temp = 0;
 
    while (fgets(val, MAX_LENGTH, stdin) != NULL)
    {
        val[strlen(val)-1] = 0;
        if (!strcmp(val, "done"))
        {
            break;
        }
        temp = atoi(val);
        if(pmaxval == NULL)
        {
            pmaxval = &temp;
            maxval = temp;
        }
        if(pminval == NULL)
        {
            pminval = &temp;
            minval = temp;
        }

        if (pmaxval != NULL && temp > maxval)
        {
            maxval = temp;
        }
        if (pminval != NULL && temp < minval)
        {
            minval = temp;
        }
     }
    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
    return 0;
}