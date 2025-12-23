#include <stdio.h> 
#define MAX_SIZE 1000

int main() 
{
	int arr[MAX_SIZE]; 
	int original_size;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &original_size); 
	for (int i = 0; i < original_size; i++)
	{
		printf("Enter the a[%d] element: ", i);
		scanf("%d", &arr[i]);
	}
	printf("Elements of original array: \n"); 
	for (int j = 0; j < original_size; j++)
	{
		printf("%d\n", arr[j]);
	}
	
	int size; 
	int temp;
	for (size = original_size; size >= 2; size--)
	{
		for (int k = 0; k < size - 1; k++)
		{
			if (arr[k] > arr[k + 1]) 
			{
				temp = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = temp;
			}
		} 
	} 
	printf("Elements of sorted array: \n"); 
	for (int l = 0; l < original_size; l++)
	{
		printf("%d\n", arr[l]);
	}	
	return 0; 
} 
			
	