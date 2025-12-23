#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int c = getchar();
    while (1 == 1)
   {
        if (c == EOF)
        {
            break;
        }
        else
        {
            putchar(c);
            c = getchar();
        }
    }
    return 0;
}
