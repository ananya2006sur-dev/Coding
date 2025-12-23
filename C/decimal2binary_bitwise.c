#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
void mystrrev(char *);
char * stripleftzeros(char *);

int main()
{
        int decimal = 0;
        int bitwisestart = 1;
        int bitwiseresult = 0;
        int bitmask = 1;
        char *binary = NULL;
        char *binarystriped = NULL;
 
        printf("Enter an INTEGER :");
        scanf("%d", &decimal);
 
        while(bitwisestart < 63 )
        {
                bitwiseresult = decimal & bitmask;
                if(bitwiseresult > 0)
                {
                        if(binary == NULL)
                        {
                                binary = (char *)malloc(2);
                                strcpy(binary, "");
                                binary = strcat(binary, "1");
                        }
                        else
                        {
                                binary = (char *)realloc(binary, strlen(binary) + 2);
                                binary = strcat(binary, "1");
                        }
                }
                else
                {
                        if(binary == NULL)
                        {
                                binary = (char *)malloc(2);
                                strcpy(binary, "");
                                binary = strcat(binary, "0");
                        }
                        else
                        {
                                binary = (char *)realloc(binary, strlen(binary) + 2);
                                binary = strcat(binary, "0");
                        }
                }
                bitmask = bitmask << 1;
                bitwisestart++;
        }
        mystrrev(binary);
        //printf("%s\n", binary);
        binarystriped = stripleftzeros(binary);
        printf("%s\n", binarystriped);
}
 
void mystrrev(char* str)
{
        int len = strlen(str);
        // pointers to start and end
        char* start = str;
        char* end = str + len - 1;
 
        while (start < end)
        {
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
        }
}

char * stripleftzeros(char* str)
{
        char *returnstr = NULL;
        int foundnonzero = 0;
        int len = strlen(str);
        char* onechar = NULL;
        // pointers to start and end
        char* start = str;
        char* end = str + len;
 
        while (start < end)
        {
                onechar = (char *)calloc(2, sizeof(char));
                sprintf(onechar, "%c", *start);
                if(strcmp(onechar, "0") == 0)
                {
                        if(foundnonzero)
                        {
                                if(returnstr == NULL)
                                {       
                                        returnstr = (char *)calloc(2, sizeof(char));
                                        strcpy(returnstr, onechar);
                                }
                                else
                                {
                                        returnstr = (char *)realloc(returnstr, strlen(returnstr) + 2);
                                        returnstr = strcat(returnstr, onechar);
                                }
                        }
                }
                else
                {
                        if(strcmp(onechar, "0"))
                        {
                                foundnonzero = 1;
                        }
                        if(returnstr == NULL)
                        {
                                returnstr = (char *)calloc(2, sizeof(char));
                                returnstr = strcpy(returnstr, onechar);
                        }
                        else
                        {
                                returnstr = (char *)realloc(returnstr, strlen(returnstr) + 2);
                                returnstr = strcat(returnstr, onechar);
                        }

                }
                free(onechar);
                onechar = NULL;
                start++;
        }
        return returnstr;
}
