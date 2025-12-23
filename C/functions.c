#include <stdio.h> 

int countdown(int n)
{
    while (n > 0)
    {
        printf("%d\n", n);
        n = n - 1;
    }
}

int main()
{
    countdown(10);
    return 0;
}