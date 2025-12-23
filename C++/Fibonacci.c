#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 1;
    int next;
    printf("%d\n", num1);
    printf("%d\n", num2);
    for (int i = 0; i < 23; i++)
    {
        next = num1 + num2;
        printf("%d\n", next);
        num1 = num2;
        num2 = next;
    }
    return 0;
}



