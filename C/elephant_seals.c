
/*Calculating average of weights of all elephant seals in a file*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_WEIGHTS 100000

int main(int argc, char* argv[])
{
    FILE *fp;
    char ch;
    char *filename = NULL;
    int allweights[MAX_WEIGHTS];
    char *individualweights = NULL;
    int arrayctr = 0;
    int totalallweights = 0;
    double avgallweights = 0.0;

    if(argc == 2)
    {
        filename = argv[1];
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
            printf("File not found\n"); //checking the existence of file
            exit(1);
        }
        while ((ch = fgetc(fp)) != EOF)
        {
            
            if(ch == ' ') //ignoring spaces in the file
            {
                continue;
            }
            if(ch != '\t') //ignoring tabs in the file
            {
                
                if(individualweights == NULL)
                {
                    individualweights = (char *)calloc(2,sizeof(char));
                    strcpy(individualweights, "");
                    sprintf(individualweights, "%s%c", individualweights, ch);
                }
                else
                {
                    individualweights = (char *)realloc(individualweights, strlen(individualweights) + 2);
                    sprintf(individualweights, "%s%c", individualweights,ch);
                }
            }
            else
            {
                
                allweights[arrayctr] = atoi(individualweights); //converting string to integer
                arrayctr++;
                free(individualweights);
                individualweights = NULL;
            }
        }
        
        allweights[arrayctr] = atoi(individualweights); //converting string to integer
        fclose(fp);
        for(int i = 0; i <= arrayctr; i++) //calculating total of all weights
        {
            totalallweights = totalallweights + allweights[i];
        }
        printf("Total of weights of all elephant seals in the file is %d\n", totalallweights);
        avgallweights = (double)totalallweights / (arrayctr + 1);
        printf("Average of weights of all elephant seals in the file is %f\n", avgallweights); //calculating average of all weights
    }
    return 0;
}

