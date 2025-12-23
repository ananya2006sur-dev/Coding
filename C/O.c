#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    FILE* fp;
    int data[7]; 
    int sum = 0;
    fp = fopen("Ananya.txt", "r");
    assert(fp != NULL);
    while (!feof(fp))
    {
        for (int i = 0; i < 7; i++)
        {
        fscanf(fp, "%d", &data[i]);
        printf("%d\n", data[i]);
        sum = sum + data[i];
        }
    }  
    printf("Sum of all the numbers is: %d\n", sum); 
    printf("Average of all the numbers is: %llf\n", (float)sum/7);
    fclose(fp);
    return 0;
}

