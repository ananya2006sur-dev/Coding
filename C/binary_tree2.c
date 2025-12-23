#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;

typedef node* BTREE;

void inorder(BTREE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }

}


BTREE create_node(int d, BTREE l, BTREE r)
{
    BTREE temp = (BTREE)malloc(sizeof(node));
    temp->data = d;
    temp->left = l;
    temp->right = r;
    return temp;
}

BTREE create_tree(int d[], int i, int size)
{
    if (i >= size)
    {
        return NULL;
    }
    else
    {
        return create_node(d[i], create_tree(d, 2 * i + 1, size), create_tree(d, 2 * i + 2, size));
    }
    
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(data) / sizeof(data[0]);
    BTREE root = create_tree(data, 0, size);
    inorder(root);
    return 0;
}