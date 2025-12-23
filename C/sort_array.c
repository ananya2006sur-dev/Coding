#include <stdio.h>
#include <stdlib.h>

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sort_array(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int d[] = {38, 94, 27, 34, 12, 45, 67, 89, 23, 56};
    int size = sizeof(d) / sizeof(d[0]);
    printf("Original array: ");
    print_array(d, size);
    printf("\nSorted array: ");
    sort_array(d, size);
    print_array(d, size);
    return 0;
} 
