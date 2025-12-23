#include <stdio.h>
#include <stdbool.h>

bool is_Palindrome(int n)
{
	int reverse_num = 0;
	int fwd = n;
	int r; 
	int new_num = n;
	while (fwd != 0)
	{
		fwd = fwd/10;
		r = new_num % 10;
		reverse_num = reverse_num*10 + r;
		new_num = fwd;
	}
	if (reverse_num == n)
	{
		return true;
	}
	return false; 
} 

int main()
{
	int num; 
	printf("Enter the input number: ");
	scanf("%d", &num); 
	printf("%d is a palindrom number: %s", num, is_Palindrome(num) ? "true" : "false");
	return 0; 
} 
	