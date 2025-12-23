#include <stdio.h>

void swap(int i, int j)
{
    int temp = i;
    i = j;
    j = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    swap(a , b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}