#include <stdio.h>

int main()
{
    int rows1, cols1, rows2, cols2, choice, i, j, k;
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &cols1);
    printf("Enter the number of rows in matrix B: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in matrix B: ");
    scanf("%d", &cols2);
    int a[rows1][cols1];
    int b[rows2][cols2];
    int c[rows1][cols1];
    int d[rows1][cols1];
    int e[rows1][cols2];
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
        {
            printf("Enter the a[%d][%d] element: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < rows2; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            printf("Enter the b[%d][%d] element: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Enter 1 to perform addition, 2 to perform subtraction, 3 to perform multiplication on the matrices A and B: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: 
        if (rows1 == rows2 && cols1 == cols2)
        {
            for (i = 0; i < rows1; i++)
            {
                for (j = 0; j < cols1; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
        }
        else 
        {
            printf("Can't perform addition\n");
            break;
        }
        printf("The result matrix is: \n");
        for (i = 0; i < rows2 ;i++)
        {
            for (j = 0; j < cols2; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
        break;

        case 2:
        if (rows1 == rows2 && cols1 == cols2)
        {
            for (i = 0; i < rows1; i++)
            {
                for (j = 0; j < cols1; j++)
                {
                    d[i][j] = a[i][j] - b[i][j];
                }
            }
        }
        else
        {
            printf("Can't perform subtraction\n");
            break;
        }
        printf("The result matrix is: \n");
        for (i = 0; i < rows2 ;i++)
        {
            for (j = 0; j < cols2; j++)
            {
                printf("%d\t", d[i][j]);
            }
            printf("\n");
        }
        break;

        case 3:
        if (cols1 == rows2)
        {
            for (i = 0; i < rows1; i++)
            {
                for (j = 0; j < cols2; j++)
                {
                    e[i][j] = 0;
                    for (k = 0; k < rows2; k++)
                    {
                        e[i][j] = e[i][j] + a[i][k]*b[k][j];
                    }
                }
            }
        }
        else
        {
            printf("Can't perform multiplication\n");
            break;
        }
        printf("The result matrix is: \n");
        for (i = 0; i < rows1 ;i++)
        {
            for (j = 0; j < cols2; j++)
            {
                printf("%d\t", e[i][j]);
            }
            printf("\n");
        }
        break;

        default:
        printf("Invalid Input");
        break;
    }
    return 0;
}