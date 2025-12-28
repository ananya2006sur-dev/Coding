#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

struct book
{
	int id; 
	char title[20]; 
	char author[20]; 
}; 
typedef struct book book; 

struct book_node
{
	book b; 
	struct book_node* next; 
}; 
typedef struct book_node bk; 

void add(bk** head, int book_id, char book_title[MAX], char book_author[MAX])
{
	bk* new_book = malloc(sizeof(bk)); 
	new_book->b.id = book_id; 
	strcpy(new_book->b.title, book_title); 
	strcpy(new_book->b.author, book_author); 
	new_book->next = NULL; 
	
	if(*head == NULL)
	{
		*head = new_book; 
		return; 
	}
	
	bk* curr = *head; 
	while(curr->next != NULL)
	{
		curr = curr->next; 
	}
	curr->next = new_book; 
} 

void delete(bk** head, int book_id)
{
	if(*head == NULL)
	{
		printf("Library is empty\n");
		return; 
	}
	bk* toDelete; 
	
	if((*head)->b.id == book_id)
	{
		toDelete = *head; 
		*head = (*head)->next; 
 		free(toDelete); 
		toDelete = NULL; 
	}
	
	bk* curr = *head; 
	while(curr->next->b.id != book_id)
	{
		curr = curr->next; 
		if(curr->next == NULL)
		{
			printf("Book of ID %d not found\n", book_id);
		}
	}
	toDelete = curr->next; 
	curr->next = toDelete->next; 
    free(toDelete); 
	toDelete = NULL;
}
		
void search(bk* head, int book_id)
{
	if(head == NULL)
	{
		printf("Library is empty\n"); 
		return; 
	}
	
	bk* curr = head; 
	while(curr->b.id != book_id)
	{
		curr = curr->next; 
		if (curr == NULL)
		{
			printf("Book with ID %d not found\n", book_id); 
			return; 
		}
	}
	printf("The details of the book: \n"); 
    if(curr != NULL)
    {
	    printf("Book ID: %d, Book Title: %s, Book Author: %s\n", curr->b.id, curr->b.title, curr->b.author); 
    }
}

void display(bk* head)
{
	bk* curr = head; 
	while (curr != NULL)
	{
		printf("Book ID: %d, Book Title: %s, Book Author: %s\n", curr->b.id, curr->b.title, curr->b.author); 
		curr = curr->next; 
	}
} 

void sort_library(bk** head)
{
	bk* curr;  
	book temp; 
	bk* last = NULL; 
	while(last != (*head)->next)
	{
		curr = *head; 
		while(curr->next != last)
		{
			if(curr->b.id > curr->next->b.id)
			{
				temp = curr->b; 
				curr->b = curr->next->b; 
				curr->next->b = temp; 
			}
			curr = curr->next; 
		}
		last = curr; 
	}
}
	

int main()
{
	bk* head = malloc(sizeof(bk)); 
	book bk1 = {103, "The Great Gatsby", "Fitzgerald"};
	head->b = bk1; 
	head->next = malloc(sizeof(bk)); 
	bk* b2 = head->next;
	book bk2 = {102, "Alice", "Lewis"};
	b2->b =  bk2; 
	b2->next = malloc(sizeof(bk)); 
	bk* b3 = b2->next; 
	book bk3 = {101, "Cinderella", "Charles"}; 
	b3->b = bk3;
	b3->next = NULL; 
	
    printf("Initial Library: \n");
	display(head);
	printf("\n"); 
	
    printf("After adding:\n"); 
	add(&head, 105, "Pride and Prejudice", "Jane Astrofer"); 
	add(&head, 104, "ABCDEFXYZ", "Ananya"); 
	
	display(head); 
	printf("\n"); 

	printf("After deleting:\n");
	delete(&head, 105); 
	display(head); 
	printf("\n"); 
	
    printf("Searching:\n");
	search(head, 104); 
	printf("\n"); 
	
    printf("After sorting:\n");
	sort_library(&head); 
	display(head); 


	return 0; 
} 
	
	
	
	
		
	
	
		
		
	
	