#include <stdio.h>
#include <stdlib.h>

struct qnode{
    int data; 
    struct qnode* next; 
};
typedef struct qnode qnode; 


void enqueue(qnode** front, qnode** rear, int new_data)
{
    qnode* new = (qnode*)malloc(sizeof(qnode)); 
    new->data = new_data; 
    new->next = NULL; 
    if(*front == NULL)
    {
        *front = new; 
        *rear = new; 
        return; 
    }
    (*rear)->next = new; 
    *rear = new; 
}

int dequeue(qnode** front)
{
    int x; 
    if(*front == NULL)
    {
        printf("Queue underflow. Cannot dequeue elements.\n");
        return -9999;
    }
    qnode* temp = *front; 
    x = (*front)->data; 
    *front = (*front)->next; 
    free(temp); 
    temp = NULL; 
    return x; 
}

void display(qnode* front)
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return; 
    }
    qnode* curr = front; 
    while(curr != NULL)
    {
        printf("%d ", curr->data); 
        curr = curr->next; 
    }
}

int main()
{
    qnode* front = NULL; 
    qnode* rear = NULL; 
    char choice; 
    int choice_int, new_data, dequeued;
    do
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice_int); 
        switch(choice_int)
        {
            case 1:
                {
                    printf("Enter data to enqueue into queue: ");
                    scanf("%d", &new_data); 
                    enqueue(&front, &rear, new_data); 
                    break; 
                }
            case 2:
                {
                    dequeued = dequeue(&front); 
                    if(dequeued != -9999)
                    {
                        printf("Dequeued element: %d\n", dequeued); 
                    }
                    break; 
                }
            case 3:
                {
                    printf("Queue elements: ");
                    display(front); 
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