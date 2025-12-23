#include <stdio.h>
#include <stdlib.h>

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) 
{
    for (int i = 0; i < queries_count; i++)
    {
        char* c = queries[i]; 
        int count = 0;
        for (int j = 0; j < stringList_count; j++)
        {
            if (strcmp(stringList[j], queries[i]) == 0);
            {
                count++;
            }
        }
        result_count[i] = count;
    }
    return result_count;
}

int main()
{
    int stringList_count = 4;
    int queries_count = 3;
    char** stringList = (char**)malloc(stringList_count*sizeof(char*));
    char** queries = (char**)malloc(queries_count*sizeof(char*));
    int* result_count = (int*)malloc(queries_count*sizeof(int));
    stringList[0] = "aba";
    stringList[1] = "baba";
    stringList[2] = "aba";
    stringList[3] = "xzxb";
    queries[0] = "aba";
    queries[1] = "xzxb";
    queries[2] = "ab";
    result_count = matchingStrings(stringList_count, stringList, queries_count, result_count);
    for (int i = 0; i < queries_count; i++)
    {
        printf("%d\n", result_count[i]);
    }
    return 0;
}