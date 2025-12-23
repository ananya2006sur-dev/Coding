#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct list
{
    int data;
    struct list* next;
};
typedef struct list list;

list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list* add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head->next = h;
    return head;
}

list* array_to_list(int d[], int size)
{
    list* head = create_list(d[size - 1]);
    for (int i = size - 2; i >= 0; i--)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void display_list(int d[], list* h)
{
   h = array_to_list(d, 10);
   printf("List of integers:\n");
   while (h != NULL)
   {
        printf("%d\n", h-> data);
        h = h->next;
   }
}

int main()
{
    int d[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = 10;
    list* head = array_to_list(d, 10);
    display_list(d, head);
    free(head);
    return 0;
}

