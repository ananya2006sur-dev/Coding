#include <stdio.h>

int main()
{
    char string[] = {'E', 'l', 'e', 'p', 'h', 'a', 'n', 't'};
    int i = 0;
    int vowel = 0;
    while (string[i] != '\0')
    {
        if (string[i] == 'A' || string[i] == 'a' || string[i] == 'E' || string[i] == 'e' || string[i] == 'I' || string[i] == 'i' || string[i] == 'O' || string[i] == 'o' || string[i] == 'U' || string[i] == 'u')
        {
            vowel++;
        }
        i++;
    }
    printf("Number of characters in the string: %d\n", i - 1);
    printf("Number of vowels in the string: %d\n", vowel);
    return 0;
}
