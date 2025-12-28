#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff; 
    int pow; 
    struct poly* next; 
}; 
typedef struct poly poly; 

poly* create_poly() 
{   poly* head; 
    poly* curr = malloc(sizeof(poly)); 
    printf("Enter the coefficient and power of the first term: "); 
    scanf("%d %d", &curr->coeff, &curr->pow); 
    curr->next = NULL; 
    head = curr; 
    char choice; 
    do 
    { 
        printf("Do you want to add a new term (y/n)?: "); 
        scanf(" %c", &choice); 
        if(choice == 'y' || choice == 'Y') 
        { 
            poly* new = malloc(sizeof(poly)); 
            printf("Enter the coefficient and power of the new term: "); 
            scanf("%d %d", &new->coeff, &new->pow); 
            new->next = NULL; 
            curr->next = new; 
            curr = curr->next; 
        } 
    } while(choice == 'y' || choice == 'Y'); 
    return head; 
}

void display(poly* head) 
{ 
    if(head == NULL) 
    { 
        printf("Polynomial doesn't exist\n"); 
        return; 
    } 
    poly* curr = head; 
    while (curr != NULL) 
    { 
        if(curr->next == NULL) 
        { 
            printf("%dx^%d", curr->coeff, curr->pow); 
        } 
        else 
        { 
            printf("%dx^%d + ", curr->coeff, curr->pow); 
        } 
        curr = curr->next; 
    } 
    printf("\n"); 
}

void sort(poly** head)
{
    poly* curr = *head; 
    poly* last; 
    while(curr->next != NULL)
    {
        curr = curr->next; 
    }
    last = curr; 
    int temp_pow; 
    int temp_coeff; 
    poly* tempNode = NULL; 
    while(last != (*head)->next)
    {
        curr = *head; 
        while(curr != last)
        {
            if(curr->pow < curr->next->pow)
            {
                temp_pow = curr->pow; 
                temp_coeff = curr->coeff; 
                curr->pow = curr->next->pow; 
                curr->coeff = curr->next->coeff; 
                curr->next->pow = temp_pow; 
                curr->next->coeff = temp_coeff; 

            }
            tempNode = curr; 
            curr = curr->next; 
        }
        last = tempNode; 
    }
}

poly* mult(poly* head1, poly* head2)
{
    poly* ptr1 = head1; 
    poly* ptr2 = head2; 
    poly* head = NULL;  
    if(ptr1 == NULL || ptr2 == NULL)
    {
        printf("One of the polynomials doesn't exist\n");
        return NULL; 
    }
    poly* curr = malloc(sizeof(poly));
    curr->coeff = ptr1->coeff * ptr2->coeff;
    curr->pow = ptr1->pow + ptr2->pow; 
    curr->next = NULL; 
    head = curr; 

    ptr2 = ptr2->next; 
    poly* new = NULL; 

    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            new = malloc(sizeof(poly)); 
            new->coeff = ptr1->coeff * ptr2->coeff; 
            new->pow = ptr1->pow + ptr2->pow; 
            new->next = NULL; 
            curr->next = new; 
            curr = new; 
            ptr2 = ptr2->next; 
        }
        ptr1 = ptr1->next; 
        ptr2 = head2; 
    }
    sort(&head); 
    curr = head; 
    poly* del = NULL;
    while(curr->next != NULL)
    {
        while(curr->pow == curr->next->pow)
        {
            curr->coeff = curr->coeff + curr->next->coeff; 
            del = curr->next; 
            curr->next = del->next; 
            free(del); 
            del = NULL; 
        }
        curr = curr->next; 
    }
    curr = head; 
    while(curr != NULL && curr->coeff == 0)
    {
        del = curr; 
        curr = del->next; 
        free(del); 
        del = NULL; 
    }
    if(curr == NULL)
    {
        printf("Product of the two polynomials is 0\n");
        return NULL; 
    }
    head = curr; 
    while(curr->next != NULL)
    {
        if(curr->next->coeff == 0)
        {
            del = curr->next;
            curr->next = del->next; 
            free(del); 
            del = NULL; 
        }
        else
        {
            curr = curr->next; 
        }
    }
    return head; 
}

int main()
{
    poly* head1 = NULL; 
    poly* head2 = NULL; 
    poly* head3 = NULL; 
    printf("Create the first polynomial:\n"); 
    head1 = create_poly(); 
    printf("Create the second polynomial:\n"); 
    head2 = create_poly(); 
    printf("First polynomial: ");
    display(head1); 
    printf("Second polynomial: ");
    display(head2); 
    head3 = mult(head1, head2); 
    if(head3 != NULL)
    {
        printf("Product of the two polynomials: ");
        display(head3); 
    }
    return 0;
}