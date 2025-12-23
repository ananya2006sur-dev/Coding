#include <stdio.h>

int main()
{
    int guess;
    while (scanf("%d", &guess) != EOF)
    {
        if (guess == 42)
        {
            printf("Nice Work!\n");
            break;
        }
        else if (guess < 42)
        {
            printf("Too Low\n");
        }
        else if (guess > 42)
        {
            printf("Too High\n");
        }

    }
    return 0;
}