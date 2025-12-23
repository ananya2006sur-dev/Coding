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
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            blanks = blanks + 1;
        }
        else if (c == '\n')
        {
            newlines = newlines + 1;
        }
    }
    printf("%d %d", blanks, newlines);
}