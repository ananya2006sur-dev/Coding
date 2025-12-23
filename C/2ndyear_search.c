#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX]; 
    int i, j, size, num, choice, temp, low, high, mid; 
    char c; 
    printf("Do you want to add a new element? (y/n): "); 
    scanf(" %c", &c); 
    i = 0; 
    while(c != 'n' && c != 'N' && i < MAX - 1)
    {
        if(c != 'y' && c != 'Y')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            printf("Do you want to add a new element? (y/n): ");
            scanf(" %c", &c);
            continue;
        }
        
        printf("Enter the element: "); 
        scanf("%d", &arr[i]); 
        printf("Do you want to add a new element? (y/n): ");
        scanf(" %c", &c);
        i++; 
    }
    if (i == MAX - 1 && (c == 'y' || c == 'Y'))
    {
        printf("Array is full. Cannot add more elements.\n");
    }
    size = i; 
    printf("Array\n"); 
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("\n");
    printf("Enter the element to search: ");
    scanf("%d", &num);
    printf("Choose search algorithm:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            for(i = 0; i < size; i++)
            {
                if(arr[i] == num)
                {
                    printf("Element %d found at index %d\n", num, i); 
                    break; 
                }
            }
            if(i == size)
            {
                printf("Element %d not found in the array.\n", num); 
            }
            break; 

        case 2:
            for(i = 0; i < size - 1; i++)
            {
                for(j = 0; j < size - i - 1; j++)
                {
                    if(arr[j] > arr[j + 1])
                    {
                        temp = arr[j]; 
                        arr[j] = arr[j + 1]; 
                        arr[j + 1] = temp; 
                    }
                }
            }
            low = 0; 
            high = size - 1; 
            while(low <= high)
            {
                mid = (low + high)/2; 
                if(num < arr[mid])
                {
                    high = mid - 1; 
                }
                else if (num > arr[mid])
                {
                    low = mid + 1; 
                }
                else
                {
                    printf("Element %d found at index %d\n", num, mid); 
                    break;
                }
            }
            if(low > high)
            {
                printf("Element %d not found in the array.\n", num);
            }
            break; 

        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
    }
    return 0;
}
