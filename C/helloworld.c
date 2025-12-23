#include <stdio.h>
#include <ctype.h>

int main() 
{
    char str[] = "HeLLo WoRLd!";
	int size = sizeof(str)/sizeof(str[0]);
    
    for (int i = 0; i < size; i++) {
        if (isupper(str[i]))
		{
           str[i] = tolower(str[i]);
		}
        else if (islower(str[i]))
		{
           str[i] = toupper(str[i]);
		} 
    }

    printf("Toggled string: %s\n", str);
    return 0;
}