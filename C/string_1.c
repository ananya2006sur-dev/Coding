#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char poem[1000];
    char* string = &poem[0];
    printf("Enter the string:  ");
    fgets(string, 1000, stdin);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
        }
    }
    printf("The string is %s\n", string);
}