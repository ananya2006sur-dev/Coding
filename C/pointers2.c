#include <stdio.h>

void swap(int* i, int* j)
{
    int temp = *i; 
    *i = *j;
    *j = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    int* c = &a;
    int* d = &b;
    swap(c, d);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}