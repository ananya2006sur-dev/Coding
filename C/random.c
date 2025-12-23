#include <stdio.h> // has printf() and scanf()
#include <stdlib.h> // has rand() and srand()
#include <time.h> // has time()

#define MAX_ELEPHANT_SEAL_WT 8800
#define MIN_ELEPHANT_SEAL_WT 4400

#define RANGE 4400
#define POPULATION 1000
#define WEIGHT_OVER rand() % RANGE
#define WEIGHT WEIGHT_OVER + MIN_ELEPHANT_SEAL_WT
#define FILL for (int i = 0; i < POPULATION; i++) \
    { \
        weights[i] = WEIGHT; \
    }

void print_data(int d[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d%c", d[i], ' ');
        if ((i + 1) % 10 == 0)
        {
            printf("%c",'\n');
        }
    }
}

int main()
{
    int weights[POPULATION];
    srand(time(NULL));
    FILL
    print_data(weights, POPULATION);
    return 0;
}