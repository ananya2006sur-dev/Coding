/* A program to create a binary tree and traverse its nodes and print the data in it by using the numbers in an input file */

#include <stdio.h>
#include <stdlib.h>

struct node // Defining a structure node to represent a node in a binary tree
{
    int data;

    struct node* left; // Pointer to the left child of the node

    struct node* right; // Pointer to the right child of the node
};
typedef struct node node; // Defining a new data type node

void inorder(node* root) // Function to print the inorder traversal of a binary tree
{
    if (root != NULL) 
    {
       inorder(root->left); // Recursively call the function inorder to print the left subtree of the root

       printf("%d ", root->data); // Print the data of the current root

       inorder(root->right); // Recursively call the function inorder to print the right subtree of the root
    }
}

void create_tree(node** root, int data) // Function to create a binary tree
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (*root == NULL) // If the root is NULL
    {
        *root = temp; // Assign the new node to the root
    }
    else
    {
        node* current = *root;
        node* parent = NULL;
        while (current != NULL) // Loop to find the correct position for the new node
        {
            parent = current;
            if (data < current->data) // If the data is less than the data of the current node
            {
                
                current = current->left; // Move to the left child of the current node
            
            }
            else // If the data is greater than or equal to the data of the current node
            {
                
                current = current->right; // Move to the right child of the current node

            }
        }
        if (data < parent->data) // If the data is less than the data of the parent node
        {

            parent->left = temp; // Assign the new node to the left child of the parent node

        }
        else // If the data is greater than or equal to the data of the parent node
        {

            parent->right = temp; // Assign the new node to the right child of the parent node

        }
    }
}

int main()
{
    FILE* input;

    input = fopen("input.txt", "r");

    int n; // No. of integers to be read from the input.txt file
    
    fscanf(input, "%d", &n); // Scanning the first integer in the input file and storing it in n variable
    
    int* d = malloc(n * sizeof(int)); // Allocating memory for an integer array of size n
    
    printf("Number of nodes in the binary tree is: %d\n", n); // Printing the number of integers to be read from the input file

    node* root = NULL; // Creating a root node for the binary tree

    for (int i = 0; i < n; i++) // Loop to read the integers from the input file and store them in the array d
    {
        fscanf(input, "%d", &d[i]);
        create_tree(&root, d[i]); // Creating a binary tree using the integers read from the input file
    }

    printf("Inorder traversal of the binary tree is:\n"); // Printing the inorder traversal of the binary tree using the inorder function

    inorder(root); // Calling the inorder function to print the inorder traversal of the binary tree

    fclose(input);

    free(d);

    return 0;
}

