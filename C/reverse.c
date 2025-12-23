/* A program to replace more than 1 blanks with only 1 blank in a input string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000 
#define NO_OF_LINES 4 
#include <math.h>

int main()
{
    char str[MAX_LENGTH]; 
    int i;
    int j;
    int k;
    for (i = 1; i <= NO_OF_LINES; i++) 
    {
        fgets(str, MAX_LENGTH, stdin); 
        for (j = 0; j < strlen(str); j++) 
        {
            if (str[j] == ' ' && str[j + 1] == ' ') 
            {
                while (str[j + 1] == ' ') 
                {
                    for (k = j; k < strlen(str); k++)
                    {
                    str[k] = str[k + 1];
                    }
                }
            }
            else if (str[j] == '\n') 
            {
                str[j] = '\0';
            }
            else
            {
                continue;
            }
        }
        printf("%s\n", str);
    }
    
    return 0;
    
}

