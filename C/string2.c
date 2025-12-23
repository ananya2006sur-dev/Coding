#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  	int c;
  	while (1 == 1)
    {
      	c = getchar();
      	if (c == EOF)
        {
          	break;
        }
        if (c == ' ' || c == '\n')
        {
          	c = '\n';
        }
      	putchar(c);
    }
  	return 0;
}
    