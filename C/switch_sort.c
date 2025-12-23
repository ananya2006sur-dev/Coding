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
	
	int choice;
	printf("Enter \n 1. For bubble sort \n 2. For insertion sort \n 3. For selection sort \n");  
	scanf("%d", &choice); 
	
	int temp; 
	
	switch(choice)
	{
		case 1: 
		int size; 
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
		break; 
		
		case 2:
		int key;
		int j; 
		for(int i = 1; i < size; i++)
		{
			key = arr[i]; 
			j = i;
			while ((j - 1) >= 0 && key < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = key; 
				j--;
			} 
		} 
		break; 
		
		case 3:
		int min;
		int min_index;
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
		break; 
		
		default:
		printf("Invalid choice, kindly enter either of 1,2,3"); 
	}
	
	printf("Elements of sorted array: \n"); 
	for (int l = 0; l < original_size; l++)
	{
		printf("%d\n", arr[l]);
	}	
	return 0;
}