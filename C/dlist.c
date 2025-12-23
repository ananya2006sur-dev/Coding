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
    for(int i = 0; )
}