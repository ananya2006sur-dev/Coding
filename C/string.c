#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
    char poem[MAX_LENGTH];
    int blanks = 0;
    int newlines = 0;
    int c;
    char *inputstring = NULL;
    char eachchar;
    while ( 1 == 1)
    {
        fgets(poem, MAX_LENGTH, stdin);
        if(poem[0] == '\n')
        {
            break;
        }   
        inputstring = &poem[0];
        eachchar = *inputstring;
        while (eachchar != '\0')
        {
            if (eachchar == ' ')
            {
                blanks = blanks + 1;
            }
            else if (eachchar == '\n')
            {
                newlines = newlines + 1;
            }
            inputstring++;
            eachchar = *inputstring;
        }
    }
    printf("%d %d", blanks, newlines);
}