#include <stdio.h>
#include <stdlib.h>

void copy(FILE* fp1, FILE* fp2)
{
    int c;
    while ((c = getc(fp1)) != EOF)
    {
        putc(c, fp2);
    }
}

int main()
{
    FILE* f1 = fopen("Ananya.txt", "r");
    FILE* f2 = fopen("empty.txt", "w");
    copy(f1, f2);
    fclose(f1);
    fclose(f2);
    return 0;
}