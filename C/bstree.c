#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct bstree
{
	int data;
	struct bstree *lchild, *rchild; 
}node; 

node* createbstree(node*);
node* getnode(); 
node* search(node*, int); 
void inorder_rec(node*); 
void preorder_rec(node*); 
void postorder_rec(node*); 
node* del(node*); 

int main()
{
	node* root = NULL, *temp; 
	int ch = 0, srno = 0; 
	printf("\nCreate the BST\n"); 
	root = createbstree(root); 
	do
	{
		printf("\n1. inorder with recursion"); 
		printf("\n2. preorder with recursion"); 
		printf("\n3. postorder with recursion"); 
		printf("\n4. search the node"); 
		printf("\n5. Delete node"); 
		printf("\n6. exit"); 
		printf("\nenter your choice:"); 
		scanf("%d", &ch); 
		switch(ch)
		{
			case 1: 
				printf("\n Inorder with recursion\n");
				inorder_rec(root); 
				break; 
				
			case 2:
				printf("\n Preorder with recursion\n"); 
				preorder_rec(root); 
				break; 
				
			case 3:
				printf("\n Postorder with recursion\n"); 
				postorder_rec(root); 
				break; 
			
			case 4:
				printf("\nEnter the search data:"); 
				scanf("%d", &srno); 
				temp = search(root,srno); 
				if (temp == NULL)
				{
					printf("\n Node is not found in the tree\n"); 
				}
				else
				{
					printf("\n The node having data %d is found\n", temp->data); 
				}
				break; 
			
			case 5:
				root = del(root); 
				inorder_rec(root); 
				break; 
				
			default: exit(0); 
		}
	} while(ch != 6); 
	return 0; 
}

node* createbstree(node* root)
{
	node* newnode = NULL, *oldnode = NULL;
	char ch;
	do
	{
		newnode = getnode(); 
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			oldnode = root; 
			while(1)
			{
				if(newnode->data < oldnode->data)
				{
					if(oldnode->lchild == NULL)
					{
						newnode = oldnode->lchild; 
						break;
					}
					else
					{
						oldnode = oldnode->lchild; 
					}
				}
				else
				{
					if(oldnode->rchild == NULL)
					{
						newnode = oldnode->rchild; 
						break; 
					}
					else
					{
						oldnode = oldnode->rchild; 
					}
				}
			}
		}
		printf("\nDo you want to add more nodes?(y/n)");
		scanf(" %c", &ch); 
	} while(ch != 'n'); 
	return root; 
}

node* getnode()
{
	node* temp = NULL; 
	temp = (node*)malloc(sizeof(node)); 
	if(temp == NULL)
	{
		printf("\nmemory allocation error!"); 
		exit(0); 
	}
	else
	{
		temp->lchild = NULL; 
		temp->rchild = NULL; 
		printf("\nenter the data:"); 
		scanf("%d", &temp->data); 
	}
	return temp; 
}

node* search(node* pt, int srno)
{
	if(pt == NULL)
	{
		return NULL; 
	}
	while(pt)
	{
		if(srno == pt->data)
		{
			return pt; 
		}
		else if(srno < pt->data)
		{
			pt = pt->lchild; 
		}
		else
		{
			pt = pt->rchild; 
		}
	}
	return NULL; 
}

void inorder_rec(node* pt)
{
	if(pt != NULL)
	{
		inorder_rec(pt->lchild); 
		printf("\t%d", pt->data); 
		inorder_rec(pt->rchild); 
	}
}

void preorder_rec(node* pt)
{
	if(pt != NULL)
	{
		printf("\t%d", pt->data); 
		preorder_rec(pt->lchild); 
		preorder_rec(pt->rchild); 
	}
}

void postorder_rec(node* pt)
{
	if(pt != NULL)
	{
		postorder_rec(pt->lchild); 
		postorder_rec(pt->rchild); 
		printf("\t%d", pt->data); 
	}
}

node* del(node* root)
{
	int no; 
	node* temp, *prev, *x, *succ; 
	printf("\n\tenter the data to be deleted:"); 
	scanf("%d", &no); 
	temp = root; 
	prev = temp; 
	while(temp != NULL)
	{
		if(temp->data == no)
		{
			break; 
		}
		prev = temp; 
		if(no < temp->data)
		{
			temp = temp->lchild; 
		}
		else
		{
			temp = temp->rchild; 
		}
	}
	if(temp->lchild == NULL && temp->rchild == NULL)
	{
		if(prev->lchild == temp)
		{
			prev->lchild == NULL; 
		}
		else
		{
			prev->rchild == NULL; 
		}
		printf("\n Leaf node is deleted\n"); 
	}
	else if(temp->rchild != NULL && temp->lchild == NULL)
	{
		if(prev->lchild == temp)
		{
			prev->lchild = temp->rchild; 
		}
		else
		{
			prev->rchild = temp->rchild; 
		}
		printf("\n Node with right subtree is deleted\n"); 
	}
	else if(temp->rchild == NULL && temp->lchild != NULL)
	{
		if(prev->lchild == temp)
		{
			prev->lchild = temp->lchild; 
		}
		else
		{
			prev->rchild = temp->lchild; 
		}
		printf("\n Node with left subtree is deleted\n"); 
	}
	else if(temp->lchild != NULL && temp->rchild != NULL)
	{
		succ = temp;
		x = temp->rchild; 
		while(x != NULL)
		{
			prev = succ; 
			succ = x; 
			x = x->lchild; 
		}
		temp->data = succ->data; 
		if(temp->rchild != succ)
		{
			prev->lchild = succ->rchild; 
		}
		else
		{
			prev->rchild = succ->rchild; 
		}
		temp = succ; 
		printf("\n Node with both subtree is deleted using inorder successor method\n"); 
	}
	
	free(temp); 
	return root; 
}
	