/* A program to rearrange the integers of a list in sorted order of their values */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list // Defining a structure named list
{
    int data;
    struct list* next;
};
typedef struct list list; // Defining a new type list

void swap (list* i, list* j) // Function to swap the values of two integer variables
{
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}

list* create_list(int n) // Function to create a list of n integers
{
    list* pprevious = NULL;
    list* p = malloc(sizeof(list)); // Allocating memory for the head of the list
    list* head = p;
    srand(time(0));
    for (int i = 0; i < n; i++) // Loop to generate n random integers and store them in the list
    {
        if(pprevious != NULL)
        {
            p = malloc(sizeof(list)); // Allocating memory for the next node of the list
            pprevious->next = p;
        }
        p->data = rand() % 1000;
        p->next = NULL;
        pprevious = p;
    }
    return head;
}

void print_list(list* l) // Function to print the integers of a list l (having n integers) in rows 0f 5
{
    int i = 1;
    while (l != NULL) // Loop to print the integers of the list one-by-one
    {
        printf("%d ", l->data);
       
        if (i % 5 == 0)
        {
            printf("\n");
        }
       
        l = l->next;
        i++;
    }
}

void bubblesort_list(list* l, int n) // Function to sort n integers in a list l in ascending order
{
    list *this = NULL;
    list *afterthis = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        list* p = l; 
        for (int j = 0; j < n - 1; j++) // Loop to compare adjacent integers
        {
            this = p;
            afterthis = p->next;
            int d1 = this->data;
            int d2 = afterthis->data;
            if (d1 > d2) // If the first integer is greater than the second, swap them
            {
                swap(this, afterthis);
            }
            p = p->next;
        }
    }
}

int main() 
{
    list* head = NULL; // Defining a list pointer and initializing it to NULL
    int n = 100; // Number of integers in the list
    head = create_list(n); 
    printf("Original list:\n"); 
    print_list(head); // Printing the original list
    printf("\nSorted list:\n");  
    bubblesort_list(head, n);
    print_list(head); // Printing the sorted list
    free(head); // Freeing the memory allocated for the list
    return 0;
}

