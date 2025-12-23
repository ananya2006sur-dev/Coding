#include <stdio.h>

int main()
{
    int n;
    for (int i = 1; i <= 5; i++) 
    {
        printf("Enter your answer:"); // Asking the user to enter the answer
        scanf("%d", &n);

        if (n == 10) 
        {
            printf("Congrats! You entered the correct answer.\n"); // If the user enters the correct answer
            break;
        }
        else if (n != 10 && i < 5) 
        {
            printf("Sorry! You entered the wrong answer. Try Again\n"); // If the user enters the wrong answer less than 5 times
            continue;
        }
        else if (n != 10 && i == 5)
        {
            printf("You have exhausted all your attempts. The correct answer is 10\n"); // If the user enters the wrong answer 5 times
        }
        
    }
    return 0;
}