#include <stdio.h>
#include <malloc.h>
#include <string.h>
void dec2binary(int, char **);
 
int main()
{
        int decimal = 0;
        char *binary = NULL;
        printf("%s", "Enter INTEGER ");
        scanf("%d", &decimal);
        dec2binary(decimal, &binary);
        printf("%s%d=%s\n", "Binary for decimal ", decimal, binary);
        if(binary != NULL)
        {

                free(binary);
                binary = NULL;
        }
        return 0;
}
 
void dec2binary(int decimal, char** binary)
{
        int binaryNum[32];
        int j = 0;
        char *binchar = NULL;
 
        int i = 0;
        while (decimal > 0)
        {
                binaryNum[i] = decimal % 2;
                decimal = decimal / 2;
                i++;
        }
 
        *binary = (char *)calloc(i + 1, sizeof(char));
        for (j = i - 1; j >= 0; j--)
        {
                binchar = (char *)malloc(2);
                sprintf(binchar, "%d", binaryNum[j]);
                *binary = strcat(*binary, binchar);
                free(binchar);
                binchar = NULL;
        }

}