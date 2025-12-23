#include <stdio.h>

int main()
{
    int num = 1;
    start:
    if (num <= 5)
    {
        printf("Number: %d\n", num);
        num++;
        goto start;
    }
    printf("Loop ended.\n");
    return 0;
}

