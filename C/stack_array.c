#include <stdio.h>
#define MAX 20 

struct stack
{
    int stk[MAX]; 
    int top; 
};
typedef struct stack stack;

void display(stack s)
{
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return; 
    }
    for(int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.stk[i]);
    }
}

void push(stack *s, int value)
{
    if(s->top == MAX - 1)
    {
        printf("Stack is Full\n");
        return; 
    }
    s->top++; 
    s->stk[s->top] = value;
}

int pop(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n"); 
        return -9999; 
    }
    int num = s->stk[s->top]; 
    s->top--; 
    return num; 
}

int main()
{
    stack s; 
    s.top = -1; 
    printf("Enter the first element of the stack: "); //Adding first element in the stack
    s.top++; 
    scanf("%d", &s.stk[s.top]);
    char choice = 'y'; 
    do // Adding more elements in the stack
    {
        printf("Do you want to add another element? (y/n): "); 
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            if(s.top == MAX - 1) // Stack Overflow condition
            {
                printf("Stack Overflow\n"); 
                break; 
            }
            s.top++; 
            printf("Enter the next element of the stack: ");
            scanf("%d", &s.stk[s.top]);
        }
    } while(choice == 'y' || choice == 'Y'); // End of adding elements in the stack

}