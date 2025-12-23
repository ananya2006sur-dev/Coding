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
	
	int key;
	int j; 
	int temp; 
	
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
	printf("Elements of sorted array: \n"); 
	for (int l = 0; l < size; l++)
	{
		printf("%d\n", arr[l]);
	}	
	return 0; 
} 
	