#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int mass;
    long long energy;
    printf("Enter the mass of the object in kg: ");
    scanf("%d", &mass);
    energy = mass * pow(3 * pow(10, 8), 2);
    printf("Energy = %lld J\n", energy);
    return 0;
}