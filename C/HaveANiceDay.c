#include <stdio.h>
int main() 
{
  	char line[30];
  	printf("Enter line\n");
  	fgets(line, sizeof(line), stdin);
  	printf("Line: %s", line);
}

