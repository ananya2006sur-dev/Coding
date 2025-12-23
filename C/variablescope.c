#include <stdio.h>

int main()
{
    int a = 0;
    changevalue(a);
    printf("INT=%d", a);
}

void changevalue(int a)
{
    a = 5;
}