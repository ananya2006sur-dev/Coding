#include <stdio.h>
#define MAX 10

struct Q
{
    int R, F; 
    int data[MAX];
}; 
typedef struct Q Q; 

int empty(Q *P);
int full(Q* P); 
void enqueue(Q* P, int x); 
int dequeue(Q *P); 
void BFS(int); 
void DFS(int); 
int G[MAX][MAX]; 
int n = 0; 
int visited[MAX]; 

int main()
{
    int i, j, v, op, nedges; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
    printf("Enter the number of edges: "); 
    scanf("%d", &nedges); 

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            G[i][j] = 0; 
        }
    }

    printf("Enter the graph as a list of edges (Starting vertex number is 0): \n"); 
    for(v = 0; v <nedges; v++)
    {
        printf("Enter the next adge (Start vertex, End vertex): "); 
        scanf("%d %d", &i, &j); 
        G[i][j] = 1; 
        G[j][i] = 1; 
    }

    do
    {
        printf("\n1. DFS\n 2. BFS\n 3. Display the graph\n 4. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("Enter the starting vertex for DFS: "); 
                scanf("%d", &v); 
                for(i = 0; i < n; i++)
                {
                    visited[i] = 0; 
                }
                DFS(v); 
                break; 

            case 2:
                printf("Enter the starting vertex for BFS: "); 
                scanf("%d", &v);
                for(i = 0; i < n; i++)
                {
                    visited[i] = 0; 
                }
                BFS(v);
                break;
            
            case 3:
                printf("Adjacency Matrix: \n"); 
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        printf("%d\t", G[i][j]); 
                    }
                    printf("\n");
                }
                break; 

         }
    
}   while(op != 4); 
    return 0; 
}

int empty(Q *P)
{
    if(P->F == P->R + 1)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

int full(Q* P)
{
    if(P->R == MAX - 1)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

void enqueue(Q* P, int x)
{
    if(full(P) == 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        P->R = P->R+1; 
        P->data[P->R] = x; 
    }
}

int dequeue(Q* P)
{
    int x; 
    if(empty(P) == 1)
    {
        printf("Queue is empty\n"); 
        return -1; 
    }
    else
    {
        P->F = P->F + 1; 
        x = P->data[P->F - 1]; 
        return x; 
    }
}

void BFS(int v)
{
    int i; 
    Q q; 
    q.R = -1; 
    q.F = 0; 
    for(i = 0; i < n; i++)
    {
        visited[i] = 0; 
    }
    enqueue(&q, v); 
    printf("\nVisit: \n%d", v); 
    visited[v] = 1; 
    while(!empty(&q))
    {
        v = dequeue(&q); 
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0 && G[v][i] != 0)
            {
                enqueue(&q, i); 
                visited[i] = 1; 
                printf("\n%d", i); 
            }
        }
    }
}

void DFS(int v)
{
    int i; 
    visited[v] = 1; 
    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && G[v][i] != 0)
        {
            printf("%d", i); 
            DFS(i); 
        }
    }
}