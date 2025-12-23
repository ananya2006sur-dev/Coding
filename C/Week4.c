/* A program to input integers from an input file and print their average and the maximum integer in an output file*/

#include <stdio.h> 
#include <stdlib.h>

int main()
{
    FILE* input; 
    FILE* output;
    input = fopen("input.txt", "r"); 
    int n; // No. of integers to be read from the input.txt file
    fscanf(input, "%d", &n); // Scanning the first integer in the input file and storing it in n variable
    printf("Number of integers to be read is: %d\n", n); 
    int* d = malloc(n * sizeof(int)); // Allocating memory for an integer array of size n
    printf("The read integers in the file input.txt are:\n");
    for (int i = 0; i < n; i++) // Loop to read the integers from the input file and store them in the array d
    {
        fscanf(input, "%d", &d[i]);
        printf("%d\n", d[i]);
    }
    int sum = 0;
    double avg; 
    for (int i = 0; i < n; i++) // Loop to calculate the sum of the integers in the array d
    {
        sum = sum + d[i];
    }
    avg = (double)sum / n;
    int max = d[0];
    for (int i = 1; i <= n; i++) // Loop to find the maximum integer in the array d
    {
        if (d[i] > max)
        {
            max = d[i];
        }
    }
    printf("Average of these integers: %lf\n", avg);
    printf("Maximum of these integers : %d\n", max);
    output = fopen("output.txt", "w");
    fprintf(output, "Average of the integers in input.txt file : %lf\n", avg); // Writing the average of the integers in the output file
    fprintf(output, "Maximum of the integers in input.txt file: %d\n", max); // Writing the maximum integer in the output file
    fclose(input);
    free(d); 
    fclose(output);
    return 0;
}

