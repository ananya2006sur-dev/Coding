#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 
typedef struct node node; 

int main()
{
    node* head; 
    node* curr = malloc(sizeof(node)); 
    printf("Enter data for first node: "); 
    scanf("%d", &curr->data); 
    curr->prev = NULL; 
    head = curr; 
    char choice = 'y'; 
   
    do
    {
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'y' || choice == 'Y')
        {
            node* newnode = malloc(sizeof(node));
            printf("Enter data for new node: ");
            scanf("%d", newnode->data); 
            curr->next = newnode; 
            newnode->prev = curr; 
            curr = newnode; 
            curr->next = NULL; 

        }
    } while(choice == 'y' || choice == 'Y'); 
    

    
}