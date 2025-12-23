/* A program to rearrange the integers of list in their sorted values*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list // Defining a structure named list
{
    int data;
    struct list* next;
};
typedef struct list list; // Defining a new type list

void create_list(list** head, int n) // Function to create a list of n integers 
{
    *head = (list *)malloc(sizeof(list)); // Allocating memory for the head of the list
    list* p = *head; 
    srand(time(0)); // Seeding the random number generator
    for (int i = 0; i < n; i++) // Loop to assign random integers to the list
    {
        p->data = rand() % 1000;
        if (i < n - 1) 
        {
            p->next = malloc(sizeof(list)); // If the integer is not the last integer in the list, allocating memory for the next integer in the list
            p = p->next;
        }
        else // If the integer is the last integer in the list
        {
            p->next = NULL; // Assigning NULL to the next pointer of the last integer in the list
        }
    }
}

void print_list(list* head) // Function to print the integers of a list (having n integers) in rows of 5
{
    list* p = head;
    int i = 1;
    while (p != NULL) // Loop to print the integers of the list
    {
        printf("%d ", p->data);
        /*
        if (i % 5 == 0) 
        {
            printf("\n"); // Printing a new line after every 5 integers
        }
        */
        p = p->next;
        i++;
    }
}

void swap(list* l1, list* l2) // Function to swap the data of two next pointers/heads in a list 
{
    int temp = l1->data;
    l1->data = l2->data;
    l2->data = temp;
}

void bubblesort_list(list* head, int n) // Function to sort n integers in a list in ascending order 
{
    for (int i = 0; i < n - 1; i++) // Loop to sort the integers in the list
    {
        for (int j = 0; j < n - i; j++) // Loop to compare the integers of the list
        {
            list* p = head;
            for (int k = 0; k < j; k++) // Loop to reach the jth integer of the list
            {
                if (p->data > p->next->data)
                {
                    swap(p, p->next); // Swapping the data of the jth and (j+1)th integers of the list if the jth integer is greater than the (j+1)th integer
                }
                p = p->next;
            }
        }
    }
}

int main()
{
    //list* head = malloc(sizeof(list)); // Allocating memory for the head of the list
    list* head = NULL; // Defining a list pointer and initializing it to NULL
    int n = 10; // Number of integers in the list
    create_list(&head, n); // Creating a list of n integers
    printf("Original list:\n"); 
    print_list(head); // Printing the original list
    bubblesort_list(head, n);
    printf("\nSorted list:\n");
    print_list(head); // Printing the sorted list
    free(head); // Freeing the memory allocated for the head of the list
    return 0;
}
