/* A program too create a doubly-linked list and remove duplicate data/integers from it*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node // Structure to represent a node of a doubly-linked list
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node; // Defining a new data type node

void create_list(node** h, int n) // Function to create a doubly-linked list of n nodes
{
    node *previousp = NULL;
    node* p = NULL; // Pointer to the current node
    *h = (node *)malloc(sizeof(node)); // Allocating memory for the first node
    if(p == NULL)
    {
        p = *h;
    }
	for (int i = 0; i < n; i++) // Loop to create n nodes
	{
		if (i == 0) // If the node is the first node
		{
			p->prev = NULL; // The previous pointer of the first node is NULL
			p->data = rand() % 50; 
            p->next = NULL;
            previousp = p; 
		}
		else
		{
            p = (node *)malloc(sizeof(node)); // Allocating memory for the next node
			p->prev = previousp; // The previous pointer of the next node is the current node
			p->next = NULL;
			p->data = rand() % 50;
            previousp->next = p;
            previousp = p; 
		}
    }
}



void print_list(node* h) // Function to print the data of a doubly-linked list
{
    node* p = h;
    while (p != NULL) // Loop to print the data of each node
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int n = 200; // Number of nodes in the list
    node* head = NULL;
    create_list(&head, n);
    printf("Original list:\n");
    print_list(head); // Printing the original list
    printf("List after removing duplicate data:\n");
    node* p = head;
    node *tempstore = NULL;
    while (p != NULL) // Loop to remove duplicate data from the list
    {
        node* temp = p->next;
        while (temp != NULL) // Loop to compare the data of the current node with the data of the next nodes
        {
            if (p->data == temp->data) // If the data of the current node is equal to the data of the next node
            {
                tempstore = temp->next;
                if(tempstore == NULL)
                {
                    temp->prev->next = NULL;
                    free(temp);
                    temp = NULL;
                    temp = tempstore;
                    continue;
                }
                else
                {
                    tempstore->prev->prev->next = tempstore;
                    tempstore->prev = temp->prev;
                    free(temp);
                    temp = NULL;
                    temp = tempstore;
                }
            }
            else // If the data of the current node is not equal to the data of the next node
            {
                temp = temp->next;
            }
        }
        p = p->next; // Moving to the next node
    }
    print_list(head); // Printing the list after removing duplicate data
    return 0;
}