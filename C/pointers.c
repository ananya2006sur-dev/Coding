#include <stdio.h>

int main()
{
    int sum = 408;
    int*p = &sum; 
    printf("Sum is at address %lu\n", p);
}