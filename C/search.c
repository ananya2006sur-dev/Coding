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
	printf("Elements of the array: \n"); 
	for (int j = 0; j < size; j++)
	{
		printf("%d\n", arr[j]);
	}
	
	int choice;
	printf("Enter \n 1. For linear search \n 2. For binary search \n: ");
	scanf("%d", &choice);
	int num; 
	printf("Enter the number you want to search for: ");
	scanf("%d", &num); 
	
	int flag = 0; 
	
	switch(choice)
	{
		case 1:
		for (int i = 0; i < size; i++)
		{
			if(arr[i] == num)
			{
				printf("Number %d found at index %d\n", num, i);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("Number %d not found\n", num);
		}
		break; 
		
		case 2:
		int temp; 
		flag = 0; 
		for (int i = size; i >= 2; i--)
		{
			for (int k = 0; k < i - 1; k++)
			{
				if (arr[k] > arr[k + 1]) 
				{
					temp = arr[k + 1];
					arr[k + 1] = arr[k];
					arr[k] = temp;
				}
			} 
		}
		printf("Array Sorted\n");
		int low = 0;
		int high = size - 1; 
		int mid; 
		
		while (low <= high)
		{
			mid = (low + high)/2; 
			
			if (arr[mid] == num)
			{
				printf("Number %d found at %d index", num, mid);
				flag = 1;
				break; 
			} 
			
			else if (arr[mid] < num)
			{
				low = mid + 1; 
			}
			
			else 
			{
				high = mid - 1;
			} 
		}
		if (flag == 0)
		{
			printf("Number %d not found\n", num);
		}
		break; 
		
		default:
		printf("Invalid choice, kindly enter either 1 or 2\n");
	}
	
	return 0;
} 
		
		
		
		
	
	
	
	
	
	
	