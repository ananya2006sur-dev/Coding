#include <stdio.h>

struct poly
{
	float coeff[10]; 
}; 
typedef struct poly poly; 

int main()
{
	poly p[3]; 
	int num = 10; 
	for(int i = 0; i < 2; i++)
	{
		printf("Input polynomial %d", i + 1); 
		for(int j = 0; j < num; j++)
		{
			printf("Enter the coefficient with power %d: ", j);
			scanf("%f", &p[i].coeff[j]); 
		} 
	}
	for(int k = 0; k < num; k++)
	{
		p[2].coeff[k] = p[0].coeff[k] + p[1].coeff[k];
	}
	printf("Resultant polynomial: "); 
	for(int l = 0; l < num; l++)
	{
		if(p[2].coeff[l] != 0)
		{
			if(l < num - 1)
			{
				printf("%0.2fx^%d + ", p[2].coeff[l], l); 
		    }
			if(l == num - 1)
			{
				printf("%0.2fx^%d ", p[2].coeff[l], l);
			}
		}
	}
	return 0;
} 