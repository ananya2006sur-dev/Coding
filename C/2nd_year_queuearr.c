#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct queue
{
    int q[MAX]; 
    int rear; 
    int front; 
}; 
typedef struct queue que; 

int isempty(que p)
{
    if(p.front == p.rear + 1)
    {
        return 1;
    }
    else
    {
        return 0; 
    }
}

int isfull(que p)
{
    if(p.rear == MAX - 1)
    {
        return 1;    
    }
    else
    {
        return 0; 
    }
}

void enqueue(que* p, int new)
{
    if(isfull(*p))
    {
        printf("Queue overflow. Cannot enqueue more elements.\n");
        return; 
    }
    p->rear++; 
    p->q[p->rear] = new; 
}

int dequeue(que* p)
{
    if(isempty(*p))
    {
        printf("Queue underflow. Cannot dequeue elements.\n");
        return -9999; 
    }
    int x = p->q[p->front]; 
    p->front++; 
    return x; 
}

void display(que p)
{
    if(isempty(p))
    {
        printf("Queue is empty.\n");
        return; 
    }
    for(int i = p.front; i <= p.rear; i++)
    {
        printf("%d ", p.q[i]); 
    }
}

int main()
{
    que q; 
    q.front = 0; 
    q.rear = -1; 
    int choice, new_data, dequeued; 
    do
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice); 
        switch(choice)
        {
            case 1:
                {
                    printf("Enter data to enqueue into queue: ");
                    scanf("%d", &new_data); 
                    enqueue(&q, new_data); 
                    break; 
                }
            case 2:
                {
                    dequeued = dequeue(&q); 
                    if(dequeued != -9999)
                    {
                        printf("Dequeued element: %d\n", dequeued); 
                    }
                    break; 
                }
            case 3:
                {
                    printf("Queue elements: ");
                    display(q); 
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