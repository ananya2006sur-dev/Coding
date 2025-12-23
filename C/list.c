#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data; 
    struct node *link; 
}; 
typedef struct node node; 

void display(node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n"); 
        return; 
    }
    node* curr = head; 
    while (curr != NULL)
    {
        printf("%d ", curr->data); 
        curr = curr->link; 
    }

}

void insert_at_beginning(node** head, int new_data)
{
    if (*head == NULL)
    {
        printf("List is empty.\n"); 
        return; 
    }
    node* newnode = (node*)malloc(sizeof(node)); 
    newnode->data = new_data; 
    node* ptr = *head; 
    *head = newnode; 
    newnode->link = ptr; 
}

void insert_at_end(node* head, int new_data)
{
    if (head == NULL)
    {
        printf("List is empty.\n"); 
        return; 
    }
    node* curr = head; 
    while(curr->link != NULL)
    {
        curr = curr->link; 
    }
    node* newnode = (node*)malloc(sizeof(node)); 
    newnode->data = new_data; 
    newnode->link = NULL; 
    curr->link = newnode; 

}

void revert(node** head)
{
    if(*head == NULL)
    {
        printf("List is empty.\n"); 
        return;
    }
    node* temp1 = *head; 
    node* temp2 = (*head)->link;  
    (*head)->link = NULL;  
    while (temp2 != NULL)
    {
        *head = temp2; 
        temp2 = temp2->link; 
        (*head)->link = temp1;
        temp1 = *head;
    }
}

int main()
{
    node* head = NULL; 
    node* curr = (node*)malloc(sizeof(node)); 
    printf("Enter the data for first node: "); 
    scanf("%d", &curr->data); 
    curr->link = NULL; 
    head = curr; 
    char choice; 

    do
    {
        printf("Do you want to add another node? (y/n): "); 
        scanf(" %c", &choice); 
        if (choice == 'y' || choice == 'Y')
        {
            node* newnode = (node*)malloc(sizeof(node)); 
            printf("Enter the data for the new node: "); 
            scanf("%d", &newnode->data); 
            newnode->link = NULL; 
            curr->link = newnode; 
            curr = newnode; 
        }

    } 
    while(choice == 'y' || choice == 'Y'); 
    printf("The original linked list is: ");
    display(head); 
    insert_at_beginning(&head, 100);
    printf("\nThe linked list after insertion at the beginning is: ");
    display(head);
    insert_at_end(head, 200);
    printf("\nThe linked list after insertion at the end is: ");
    display(head);
    revert(&head);
    printf("\nThe linked list after reversal is: ");
    display(head);
    return 0;
    
} 

