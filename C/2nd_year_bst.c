#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node* lchild; 
    struct node* rchild; 
};
typedef struct node node;

struct stack
{
    node* T; 
    struct stack* down; 
};
typedef struct stack stk;

void push(stk** top, node* new)
{
    stk* newnode = (stk*)malloc(sizeof(stk));
    newnode->T = new; 
    newnode->down = *top; 
    *top = newnode; 
}

node* pop(stk** top)
{
    if(*top == NULL)
    {
        printf("Stack underflow. Cannot pop elements.\n");
        return NULL; 
    }
    stk* temp = *top; 
    *top = (*top)->down; 
    node* x = temp->T; 
    free(temp); 
    temp = NULL; 
    return x; 
}

node* new;

node* getnode()
{
    new = (node*)malloc(sizeof(node)); 
    printf("Enter the data of the new node: ");
    scanf("%d", &new->data);
    new->lchild = NULL; 
    new->rchild = NULL; 
    return new; 
}

void createbstree(node** root)
{
    node* curr; 
    node* oldnode; 
    char choice;
    do
    {
        printf("Do you want to add a new node to the BST? (y/n): ");
        scanf(" %c", &choice); 
        if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            continue;
        }
        if(choice == 'y' || choice == 'Y')
        {
            curr = getnode(); 
            if(*root == NULL)
            {
                *root = curr; 
            }
            else 
            {
                oldnode = *root; 
                while(1)
                {
                    if(curr->data > oldnode->data)
                    {
                        if(oldnode->rchild == NULL)
                        {
                            oldnode->rchild = curr; 
                            break;  
                        }
                        else
                        {
                            oldnode = oldnode->rchild; 
                        }
                    }
                    else if(curr->data < oldnode->data)
                    {
                        if(oldnode->lchild == NULL)
                        {
                            oldnode->lchild = curr; 
                            break;
                        }
                        else
                        {
                            oldnode = oldnode->lchild; 
                        }
                    }
                    else
                    {
                        printf("Duplicate value. Node not added to the BST.\n");
                        break; 
                    }
                }
            }
        }
    } while(choice != 'n' && choice != 'N');
}

void preorder_nonrec(node* root)
{
    if(root == NULL)
    {
        printf("Tree is empty. Cannot perform traversal.\n");
        return;
    }
    stk* top = NULL; 
    push(&top, root); 
    node* temp; 
    while(top != NULL)
    {
        temp = pop(&top); 
        printf("%d ", temp->data); 
        if(temp->rchild != NULL)
        {
            push(&top, temp->rchild); 
        }
        if(temp->lchild != NULL)
        {
            push(&top, temp->lchild); 
        }
    }
}

void inorder_nonrec(node* root)
{
    if(root == NULL)
    {
        printf("Tree is empty. Cannot perform traversal.\n");
        return;
    }
    stk* top = NULL; 
    node* curr = root; 
    node* temp; 
    push(&top, root); 
    while(top != NULL)
    {
        while(curr->lchild != NULL)
        {
            push(&top, curr->lchild); 
            curr = curr->lchild; 
        }
        temp = pop(&top); 
        printf("%d ", temp->data);
        if(temp->rchild != NULL)
        {
            push(&top, temp->rchild); 
            curr = temp->rchild; 
        }
    }
}

void postorder_nonrec(node* root)
{
    if(root == NULL)
    {
        printf("Tree is empty. Cannot perform traversal.\n");
        return;
    }
    node* curr = root; 
    stk* top = NULL; 
    push(&top, root); 
    while(top != NULL)
    {
        while(curr->lchild != NULL || curr->rchild != NULL)
        {
            if(curr->rchild != NULL)
            {
                push(&top, curr->rchild); 
            }
            if(curr->lchild != NULL)
            {
                push(&top, curr->lchild); 
            }
            curr = top->T; 
        }
        printf("%d ", pop(&top)->data);
        if(curr == root)
        {
            break; 
        }
        while(top!= NULL && (top->T->rchild == curr || top->T->lchild == curr))
        {
            curr = pop(&top); 
            printf("%d ", curr->data);
        }
        if(top != NULL)
        {
            curr = top->T; 
        }
    }
}

void del(node** root, int d)
{
    node* delete = *root; 
    node* prev = NULL; 
    node* x; 
    node* pred; 
    node* succ; 
    if(*root == NULL)
    {
        printf("Tree is empty. Cannot delete element.\n");
        return; 
    }
    while(delete != NULL)
    {
        if(d != delete->data)
        {
            prev = delete; 
            if(d < delete->data)
            { 
                delete = delete->lchild; 
            }
            else
            {
                delete = delete->rchild; 
            }
        }
        else
        {
            printf("Element %d found\n", d);
            break; 
        }
    }
    if(delete == NULL)
    {
        printf("Element %d not found in the BST. Cannot delete.\n", d);
        return; 
    }
    if(delete->lchild == NULL && delete->rchild == NULL)
    {
        if(prev->lchild == delete)
        {
            prev->lchild = NULL;
        }
        else
        {
            prev->rchild = NULL;
        }
    }
    else if(delete->lchild != NULL)
    {
        pred = delete->lchild; 
        if(pred->rchild == NULL)
        {
            delete->data = pred->data; 
            delete->lchild = pred->lchild; 
        }
        else
        {
            x = delete; 
            while(pred->rchild != NULL)
            { 
                delete = pred; 
                pred = pred->rchild; 
            }
            x->data = pred->data;
            delete->rchild = pred->lchild;  
        }
        delete = pred; 
    }
    else if(delete->rchild != NULL) 
    {
        succ = delete->rchild; 
        if(succ->lchild == NULL)
        {
            delete->data = succ->data; 
            delete->rchild = succ->rchild; 
        }
        else
        {
            x = delete; 
            while(succ->lchild != NULL)
            { 
                delete = succ; 
                succ = succ->lchild; 
            }
            x->data = succ->data;
            delete->lchild = succ->rchild;  
        }
        delete = succ; 
    }
    free(delete);
    delete = NULL;

}



void preorder_rec(node* root)
{
    if(root == NULL)
    {
        return; 
    }
    printf("%d ", root->data); 
    preorder_rec(root->lchild); 
    preorder_rec(root->rchild); 
}

void inorder_rec(node* root)
{
    if(root == NULL)
    {
        return; 
    }
    inorder_rec(root->lchild); 
    printf("%d ", root->data);
    inorder_rec(root->rchild); 
}

void postorder_rec(node* root)
{
    if(root == NULL)
    {
        return; 
    }
    postorder_rec(root->lchild); 
    postorder_rec(root->rchild); 
    printf("%d ", root->data);
}

void search(node* root, int sn)
{
    if(root == NULL)
    {
        printf("Tree is empty. Cannot search for element.\n");
        return; 
    }
    node* curr = root; 
    while(curr != NULL)
    {
        if(sn < curr->data)
        {
            curr = curr->lchild; 
        }
        else if (sn > curr->data)
        {
            curr = curr->rchild; 
        }
        else
        {
            printf("Element %d found in the BST.\n", sn);
            break; 
        }
    }
    if(curr == NULL)
    {
        printf("Element %d not found in the BST.\n", sn);
    }
}

int main()
{
    char choice; 
    node* root = NULL;
    createbstree(&root);
    do
    {
        printf("\nBST Traversal Menu:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Search for an element\n");
        printf("5. Delete a node\n"); 
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        int choice_int; 
        scanf("%d", &choice_int); 
        switch(choice_int)
        {
            case 1:
                {
                    printf("Preorder Traversal: ");
                    //preorder_rec(root);
                    preorder_nonrec(root); 
                    printf("\n");
                    break; 
                }
            case 2:
                {
                    printf("Inorder Traversal: ");
                    //inorder_rec(root); 
                    inorder_nonrec(root);
                    printf("\n");
                    break; 
                }
            case 3:
                {
                    printf("Postorder Traversal: ");
                    //postorder_rec(root); 
                    postorder_nonrec(root);
                    printf("\n");
                    break; 
                }
            case 4:
                {
                    int sn; 
                    printf("Enter the element to search for: ");
                    scanf("%d", &sn); 
                    search(root, sn); 
                    break; 
                }
            case 5:
                {
                    int d; 
                    printf("Enter the element to delete: ");
                    scanf("%d", &d); 
                    del(&root, d); 
                    break; 
                }
            case 6:
                printf("Exiting the program\n"); 
                exit(0); 
            default:
                {
                    printf("Invalid choice. Please enter a number between 1 and 6.\n");
                    break; 
                }
        }
        do
        {
            printf("Do you want to perform another traversal? (y/n): ");
            scanf(" %c", &choice); 
            if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
            {
                printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
                printf("Do you want to perform another traversal? (y/n): ");
                scanf(" %c", &choice);
            }
            if(choice == 'n' || choice == 'N')
            {
                printf("Exiting the program.\n");
                exit(0); 
            }
            else
            {
                break; 
            }
        } while (1);
        
    } while(1);
}