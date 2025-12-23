#include <stdio.h>
int main() 
{
  	char line[30];
  	printf("Enter line\n");
  	scanf("%[^\n]", line);
  	printf("Line: %s", line);
}