#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void create_list(node* h, int n)
{
    node* previous = NULL;
    node* current = h;
    for (int i = 0; i < n; i++)
    {
          current = (node*)malloc(sizeof(node));
          current->prev = previous;
          current->data = rand() % 100;
          current->next = NULL;
          previous = current;
          current = current->next;
    }
    
}

int main()
{
    srand(time(NULL));
    int n = 5;
    node* head = NULL;
    create_list(head, n);
    node* current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    return 0;
}