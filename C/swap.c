#include <stdio.h>

int main()
{
    int i = 10;
    int j = 20; 
    { int i = 10;
      int j = 20;
      i = j;
      printf("i = %d\n", i);
    }

    { int i = 10;
      int j = 20;
      j = i;
      printf("j = %d", j);
    }
}