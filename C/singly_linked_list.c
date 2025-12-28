#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data; 
    struct node* link; 
}; 
typedef struct node node; 

void display(node* head)
{
    if (head == NULL)
    {
        printf("The list is empty\n"); 
        return; 
    }
    node* current = head; 
    while (current != NULL)
    {
        printf("%d ", current->data); 
        current = current->link; 
    }
}

void delete_at_beginning(node** head)
{
    if(*head == NULL)
    {
        printf("The list is empty\n"); 
        return; 
    }
    node* temp = *head; 
    *head = (*head)->link; 
    free(temp); 
}

void delete_at_end(node** head)
{
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    if ((*head)->link == NULL) // only one node
    {
        free(*head);
        *head = NULL;
        return;
    }
    node* ptr = *head;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
}

void insert_at_beginning(node** head, int new_data)
{
    node* ptr = malloc(sizeof(node));
    ptr->data = new_data; 
    ptr->link = *head; 
    *head = ptr; 
}

void insert_at_end(node* head, int new_data)
{
    node* temp = malloc(sizeof(node));
    temp->data = new_data; 
    temp->link = NULL; 

    node* ptr = head; 
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp; 
}

void insert(node* head, int new_data, int position)
{
    node* temp = malloc(sizeof(node)); 
    temp->data = new_data; 
    temp->link = NULL; 

    node* ptr = head; 
    for(int i = 0; i < position - 1; i++)
    {
        ptr = ptr->link; 
    }
    temp->link = ptr->link; 
    ptr->link = temp;  
}

void delete(node* head, int position)
{
    node* ptr = head; 
    for(int i = 0; i < position - 1; i++)
    {
        ptr = ptr->link; 
    }
    node* toDelete = ptr->link;
    ptr->link = toDelete->link;
    free(toDelete); 
}

void disp_rev(node* head)
{
    if (head == NULL)
    {
        return; 
    }
    disp_rev(head->link); 
    printf("%d ", head->data);
}

void revert(node** head)
{
    node* prev = NULL; 
    node* curr = *head; 
    node* next = NULL; 
    while (curr != NULL)
    {
        next = curr->link; 
        curr->link = prev; 
        prev = curr; 
        curr = next; 
    }
    *head = prev; 
}

int main()
{
    node* head = malloc(sizeof(node));
    head->data = 1; 
    node* curr1 = malloc(sizeof(node));
    curr1->data = 2;
    head->link = curr1; 
    node* curr2 = malloc(sizeof(node));
    curr2->data = 3;
    curr1->link = curr2;
    curr2->link = NULL;

    delete_at_end(&head);
    display(head);
    return 0; 
}