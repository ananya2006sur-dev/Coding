#include <stdio.h>

int mystery(int, int);

int main(void)
{
    //int result;
    //result = mystery(7,91);
    //printf("Result=%d\n", result);

    //int a[10] = {1,2,3,4,5,6,7,8,9,10}, i=6;
    //int* p = &a[0];
    //printf("%d\n",*(p + i));

    int i=0,j=1,k=2;
    printf("Result=%d\n", !!i);
}

int mystery(int p, int q)
{
    int r;
    if (( r = p % q) == 0)
    {
        return q;
    }
    else
    {
        return mystery(q, r);
    }

}