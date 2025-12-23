/* To count the no.of lines in an input string */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int no_of_lines = 0; 
    int c;
    while (1 == 1) 
    {
        c = getchar(); 
        if (c == '\n') 
        {
            no_of_lines++; 
        }
        if (c == EOF) 
        {
            break; 
        }
    }
    printf("No. of lines in text is %d", no_of_lines); 
    return 0;
}