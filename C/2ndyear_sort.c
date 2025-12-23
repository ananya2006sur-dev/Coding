#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int arr[MAX]; 
    int i, j, choice, key, size, min_index,temp; 
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
    printf("Array before sorting:\n"); 
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("\n");
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
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
            break;

        case 2:
            for(i = 1; i < size; i++)
            {
                key = arr[i]; 
                j = i;
                while((j - 1) >= 0 && key < arr[j - 1])
                {
                    arr[j] = arr[j - 1]; 
                    j--; 
                }
                arr[j] = key; 
            }
            break; 

        case 3:
            for(i = 0; i < size - 1; i++)
            {
                min_index = i; 
                for(j = i + 1; j < size; j++)
                {
                    if(arr[j] < arr[min_index])
                    {
                        min_index = j; 
                    }
                }
                temp = arr[i]; 
                arr[i] = arr[min_index]; 
                arr[min_index] = temp;
            } 
            break; 
        
        default:
            printf("Invalid choice\n"); 
    }
        printf("Array after sorting:\n");
        for(i = 0; i < size; i++)
        {
            printf("%d ", arr[i]); 
        }
        printf("\n");
        return 0;

}


    
    