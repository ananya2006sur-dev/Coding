#include <stdio.h>

int main()
{
    int i, n, max, min;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the a[%d] element: ", i + 1);
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    for (i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        else if (min > a[i])
        {
            min = a[i];
        }
    }
    printf("The minimum number in the array is: %d\n", min);
    printf("The maximum number in the array: %d", max);
    return 0;
}