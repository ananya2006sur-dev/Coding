#include <stdio.h>
#define MAX_SIZE 1000

int main()
{
	int arr[MAX_SIZE]; 
	int size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size); 
	for (int i = 0; i < size; i++)
	{
		printf("Enter the a[%d] element: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Elements of original array: \n"); 
	for (int j = 0; j < size; j++)
	{
		printf("%d\n", arr[j]);
	}
	
	int min;
	int min_index;
	int temp; 
	
	for (int k = 0; k < size - 2; k++)
	{
		min = arr[k];
		min_index = k;
		
		for (int l = k + 1; l < size; l++) 
		{
			if (arr[l] < min)
			{
				min = arr[l];
				min_index = l; 
			}
		}
		temp = arr[k];
		arr[k] = min;
		arr[min_index] = temp; 
	}
	
	printf("Elements of sorted array: \n"); 
	for (int m = 0; m < size; m++)
	{
		printf("%d\n", arr[m]);
	}	
	return 0; 
} 
		
			
		
		
	