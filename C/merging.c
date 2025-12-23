#include <stdio.h>

void merge(int a[], int b[], int c[], int how_many)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < how_many && j < how_many)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < how_many)
    { 
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < how_many)
    {
        c[k] = b[j];
        k++;
        j++;
    }
}

    void mergesort(int key[], int how_many)
{
        int j, k;
        int w[100];

        for (k = 1; k < how_many; k = k*2)
        {
            for (j = 0; j < how_many - k; j += 2*k)
            {
                merge(key + j, key + j + k, w + j, k);
            }
            for (j = 0; j < how_many; j++)
            {
                key[j] = w[j];
            }
        }
}