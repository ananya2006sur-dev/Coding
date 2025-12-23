#include <stdio.h>
#include <stdlib.h>

struct stacknode
{
    int data;
    struct stacknode* down; 
};
typedef struct stacknode stknode;

void push(stknode** top, int new)
{
    stknode* newnode = (stknode*)malloc(sizeof(stknode));
    newnode->data = new; 
    newnode->down = *top; 
    *top = newnode; 
}

int pop(stknode** top)
{
    if(*top == NULL)
    {
        printf("Stack underflow. Cannot pop elements.\n");
        return -9999; 
    }
    stknode* temp = *top; 
    *top = (*top)->down; 
    int x = temp->data; 
    free(temp); 
    temp = NULL; 
    return x; 
}

void display(stknode* top)
{
    if(top == NULL)
    {
        printf("Stack is empty.\n");
        return; 
    }
    stknode* curr = top; 
    while(curr != NULL)
    {
        printf("%d\n", curr->data); 
        curr = curr->down; 
    }
}

int main()
{
    stknode* top = NULL; 
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
                    push(&top, new_data); 
                    break; 
                }
            case 2:
                {
                    popped = pop(&top); 
                    if(popped != -9999)
                    {
                        printf("Popped element: %d\n", popped); 
                    }
                    break; 
                }
            case 3:
                {
                    printf("Stack elements: \n");
                    display(top); 
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
                printf("Exiting the program.\n");
                exit(0); 
            }
            else if(ch != 'y' && ch != 'Y')
            {
                printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            }
            else
            {
                break; 
            }
        } while(1);
    } while(1);
    return 0;
}