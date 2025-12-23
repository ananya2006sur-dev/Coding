#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack
{
    int stk[MAX]; 
    int top; 
}; 
typedef struct stack stack; 

int isempty(stack s)
{
    if(s.top == -1)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

int isfull(stack s)
{
    if(s.top == MAX - 1)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

void push(stack *s, int new)
{
    if(isfull(*s))
    {
        printf("Stack overflow. Cannot push more elements.\n");
        return; 
    }
    s->top++; 
    s->stk[s->top] = new; 
}

int pop(stack* s)
{
    if(isempty(*s))
    {
        printf("Stack underflow. Cannot pop elements.\n");
        return -9999; 
    }
    int x = s->stk[s->top]; 
    s->top--; 
    return x; 
}

void display(stack s)
{
    if(isempty(s))
    {
        printf("Stack is empty.\n");
        return; 
    }
    for(int i = 0; i <= s.top; i++)
    {
        printf("%d\n", s.stk[i]);
    }
}

int main()
{
    stack s; 
    s.top = -1; 
    int choice, new_data, popped; 
    do
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice); 
        switch(choice)
        {
            case 1:
                {
                    printf("Enter data to push onto stack: ");
                    scanf("%d", &new_data); 
                    push(&s, new_data); 
                    break; 
                }
            case 2:
                {
                    popped = pop(&s); 
                    if(popped != -9999)
                    {
                        printf("Popped element: %d\n", popped); 
                    }
                    break; 
                }
            case 3:
                {
                    printf("Stack elements: ");
                    display(s); 
                    printf("\n");
                    break; 
                }
            default:
                {
                    printf("Invalid choice. Please enter a number between 1 and 4.\n");
                    break; 
                }
        }
        do
        {
        
            printf("Do you want to perform another operation? (y/n): ");
            char ch;
            scanf(" %c", &ch);
            if(ch == 'n' || ch == 'N')
            {
                printf("Exiting program.\n");
                exit(0); 
            }
            else if (ch != 'y' && ch != 'Y')
            {
                printf("Invalid choice.\n");
            }
            else
            {
                break;
            }
        }   while(1); 
    }   while(1); 
    return 0;
}
