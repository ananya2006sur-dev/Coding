#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node* link; 
}; 
typedef struct node node;

int main()
{
    node* head; 
    node* curr = malloc(sizeof(node)); 
    printf("Enter the data for first node: "); 
    scanf("%d", &curr->data); 
    curr->link = NULL; 
    head = curr; 
    char choice = 'y';
    do
    {
        printf("Do you want to add another node? (y/n): "); 
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            node* newnode = malloc(sizeof(node)); 
            printf("Enter data for new node: ");
            scnaf("%d", &newnode->data); 
            newnode->link = NULL; 
            curr->link = newnode; 
            curr = newnode;  
        }
    } while (choice == 'y' || choice == 'Y');
    curr->link = head;
}