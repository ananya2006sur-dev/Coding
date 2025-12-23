#include <stdio.h>

int main()
{
    int c;
    FILE* file = fopen("elephant.txt", "w");
    printf("Contents of the file:\n");
    while ((c = getchar()) != EOF)
    {
        fprintf(c, file);
    }
}
