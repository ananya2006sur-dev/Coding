#include <stdio.h>

int main()
{
    int speed;
    printf("Enter the speed of the vehicle: ");
    scanf("%d", &speed);
    if (speed < 65)
        printf("No speeding ticket");
    else 
        printf("Speeding ticket");
}