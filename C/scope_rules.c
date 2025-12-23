#include <stdio.h>

int main()
{
    int i = 5;
    {
        int i = 10;
    }
    int j = 7;
    printf("%d", (i+j));
    return 0;
}