#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    typedef struct Input Input;
    struct Input
    {
        int num1;
        int num2;
        int num3;
    };

    Input inputValues;
    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    int sum;
    float average;
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    scanf("%d %d %d", &inputValues.num1, &inputValues.num2, &inputValues.num3);
    sum = inputValues.num1 + inputValues.num2 + inputValues.num3;
    average = (float)sum/3;
    printf("%d %.2f\n", sum, average);

    
    printf("%c", 'q');
}