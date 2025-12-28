#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct stack
{
    int data; 
    struct stack* link; 
};
typedef struct stack stack;

void display(stack* top)
{
    if(top == NULL)
    {
        printf("Stack is empty\n"); 
        return; 
    }
    stack* p = top; 
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->link;
    }
}

void push(stack** top, int value)
{
    stack* new = malloc(sizeof(stack)); 
    new->data = value; 
    new->link = *top; 
    *top = new; 
}

int pop(stack** top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n"); 
        return -1; 
    }
    int num = (*top)->data; 
    *top = (*top)->link; 
    return num;
}

int main()
{
    stack* top = NULL; 
    stack* p = malloc(sizeof(stack));
    printf("Enter the top element of the stack: ");
    scanf("%d", &p->data); 
    p->link = NULL; 
    top = p; 
    char choice = 'y'; 
    do
    {
        printf("Do you want to add another element beneath the top? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            stack* new = malloc(sizeof(stack));
            printf("Enter the new element: ");
            scanf("%d", &new->data); 
            p->link = new; 
            new->link = NULL; 
            p = new; 
        }
    } while (choice == 'y' || choice == 'Y');

    printf("The original stack is: "); 
    display(top);
    printf("Popped element is: %d\n", pop(&top));
    printf("The stack after popping the top element is: \n");
    display(top);
    printf("The stack after pushing 100 is: \n");
    push(&top, 100);
    display(top);
    return 0;

}

