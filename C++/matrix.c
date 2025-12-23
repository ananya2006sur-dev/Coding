#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the number of rows in matrix A");
    scanf("%d", &rows);
    printf("Enter the number of columns in matrix A");
    scanf("%d", &cols);
    int a[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the a[%d][%d] element: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < rows ;i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}   