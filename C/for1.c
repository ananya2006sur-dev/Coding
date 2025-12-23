#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
      char string[MAX_LENGTH];
      int c;
      int blanks = 0;
      int newlines = 0;
      int digits = 0;
      int alphabets = 0;
      while (1 == 1)
      {
            c = getchar();
            if (c == ' ')
            {
                  blanks++;
            }
            else if (c == '\n')
            {
                  newlines++;
            }
            else if (c >= '0' && c <= '9')
            {
                  digits++;
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                  alphabets++;
            }
            else if (c == EOF)
            {
                  break;
            }
      }
      printf("No. of blanks in text is %d\n", blanks);
      printf("No. of newlines in text is %d\n", newlines);
      printf("No. of digits in text is %d\n", digits);
      printf("No. of alphabets in text is %d\n", alphabets);
      printf("No. of special characters in text is %d\n", MAX_LENGTH - (blanks + newlines + digits + alphabets));
      return 0;
      
}      
