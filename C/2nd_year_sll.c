#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next; 
}; 
typedef struct node node; 

void display(node* head)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node* curr = head; 
    while(curr != NULL)
    {
        printf("%d ", curr->data); 
        curr = curr->next; 
    }
    printf("\n"); 
}

void insert_beg(node** head, int new_data)
{
    if(*head == NULL)
    {
        (*head)->data = new_data; 
        (*head)->next = NULL; 
        return; 
    }
    node* new = (node*)malloc(sizeof(node)); 
    new->data = new_data; 
    new->next = *head; 
    *head = new; 
}

void insert_end(node** head, int new_data)
{
    if(*head == NULL)
    {
        (*head)->data = new_data;
        (*head)->next = NULL; 
        return; 
    }
    node* new = (node*)malloc(sizeof(node));
    new->data = new_data;
    new->next = NULL; 
    node* curr = *head; 
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    curr->next = new; 
}

void delete_beg(node** head)
{
    node* temp = *head; 
    *head = (*head)->next; 
    free(temp); 
    temp = NULL; 
}

void delete_end(node* head)
{
    node* curr = head; 
    while(curr->next->next != NULL)
    {
        curr = curr->next; 
    }
    node* temp = curr->next; 
    curr->next = NULL; 
    free(temp);
    temp = NULL; 
}

void insert(node* head, int pos, int new_data)
{
    node* curr = head; 
    node* new = (node*)malloc(sizeof(node));
    new->data = new_data; 
    for(int i = 0; i < pos - 2; i++)
    {
        curr = curr->next; 
    }
    node* temp = curr->next; 
    curr->next = new; 
    new->next = temp; 
}

void delete(node* head, int pos)
{
    node* curr = head; 
    for(int i = 0; i < pos - 2; i++)
    {
        curr = curr->next;
    }
    node* temp = curr->next; 
    curr->next = temp->next; 
    free(temp);
    temp = NULL; 
}

void disp_rev(node* head)
{
    if(head->next == NULL)
    {
        printf("%d ", head->data);
        return; 
    }
    disp_rev(head->next); 
    printf("%d ", head->data);
}

void revert(node** head)
{
    node* curr, *prev, *fllwng;
    curr = *head;
    prev = NULL; 
    while(curr != NULL)
    {
        fllwng = curr->next;
        curr->next = prev; 
        prev = curr; 
        curr = fllwng; 
    }
    *head = prev; 
}

void sort(node* head)
{
    int temp; 
    node* curr, *top, *prev; 
    curr = head; 
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    top = curr; 
    curr = head; 
    while(top != head)
    {
        while(curr != top)
        {
            if(curr->data > curr->next->data)
            {
                temp = curr->data; 
                curr->data = curr->next->data; 
                curr->next->data = temp; 
            }
            prev = curr; 
            curr = curr->next; 
        }
        top = prev; 
        curr = head; 
    }
}

int main()
{
    char choice; 
    int op_choice; 
    printf("Do you want to create a linked list? (y/n): ");
    scanf(" %c", &choice);
    do
    {
        if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            printf("Do you want to create a linked list? (y/n): ");
            scanf(" %c", &choice);
            continue;
        }
    } while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    if(choice == 'n' || choice == 'N')
    {
        printf("Exiting the program.\n");
        exit(0); 
    }
    node* head = (node*)malloc(sizeof(node));
    printf("Enter data for the first node: ");
    scanf("%d", &head->data); 
    head->next = NULL; 
    node* curr = head; 
    node* new; 
    printf("Do you want to add a new node? (y/n): ");
    scanf(" %c", &choice);
    while(choice != 'n' && choice != 'N')
    {
        if(choice != 'y' && choice != 'Y')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            printf("Do you want to add a new node? (y/n): ");
            scanf(" %c", &choice);
            continue;
        }
        new = (node*)malloc(sizeof(node));
        printf("Enter data for the new node: ");
        scanf("%d", &new->data); 
        new->next = NULL; 
        curr->next = new; 
        curr = new; 
        printf("Do you want to add a new node? (y/n): ");
        scanf(" %c", &choice);
    }
    printf("Which operation do you want to perform?\n");
    printf("1. Display list\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at end\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Insert at a given position\n");
    printf("7. Delete from a given position\n");
    printf("8. Display list in reverse order\n");
    printf("9. Revert the linked list\n");
    printf("10. Sort the linked list\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &op_choice);
    do
    {
        switch(op_choice)
        {
            case 1:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot display.\n");
                        break;
                    }
                    printf("Linked list: ");
                    display(head);
                    break;
                }

            case 2:
                {
                    int new_data;
                    printf("Enter data to insert at beginning: ");
                    scanf("%d", &new_data);
                    insert_beg(&head, new_data); 
                    break;
                }

            case 3:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot insert at end.\n");
                        break;
                    }
                    int new_data;
                    printf("Enter data to insert at end: ");
                    scanf("%d", &new_data);
                    insert_end(&head, new_data); 
                    break; 
                }

            case 4:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot delete from beginning.\n");
                        break;
                    }
                    delete_beg(&head); 
                    break; 
                }

            case 5:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot delete from end.\n");
                        break;
                    }
                    delete_end(head); 
                    break; 
                }

            case 6:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot insert at position.\n");
                        break;
                    }
                    int pos, new_data;
                    printf("Enter position to insert at: "); 
                    scanf("%d", &pos); 
                    printf("Enter data to insert: ");
                    scanf("%d", &new_data);
                    insert(head, pos, new_data); 
                    break; 
                }

            case 7:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot delete from position.\n");
                        break;
                    }
                    int pos;
                    printf("Enter position to delete from: ");
                    scanf("%d", &pos); 
                    delete(head, pos); 
                    break; 
                }

            case 8:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot display in reverse order.\n");
                        break;
                    }
                    printf("Linked list in reverse order: ");
                    disp_rev(head);
                    printf("\n");
                    break; 
                }

            case 9:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot revert.\n");
                        break;
                    }
                    revert(&head); 
                    break; 
                }

            case 10:
                {
                    if(head == NULL)
                    {
                        printf("List is empty. Cannot sort.\n");
                        break;
                    }
                    sort(head); 
                    break;
                }
            default:
                {
                    printf("Invalid choice. Please enter a number between 1 and 9.\n");
                    break; 
                }
        }
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);
        do
        {
            if(choice == 'y' || choice == 'Y')
            {
                printf("Enter your choice (1-9): ");
                scanf("%d", &op_choice);
                break;
            }
            if(choice == 'n' || choice == 'N')
            {
                printf("Exiting the program.\n");
                exit(0); 
            }
            else
            {
                printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
                printf("Do you want to perform another operation? (y/n): ");
                scanf(" %c", &choice);
            }
        } while(1); 

    } while(1); 
} 