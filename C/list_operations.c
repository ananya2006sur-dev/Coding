#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list* next;
};
typedef struct list list;

int count(list* l)
{
    int count = 0;
    while (l != NULL)
    {
        count++;
        l=l->next;
    }
    return count;
}

void concat(list* l1, list* l2)
{
    while (l1->next != NULL)
    {
        l1 = l1->next;
    }
    l1->next = l2; //*(l1).next
}