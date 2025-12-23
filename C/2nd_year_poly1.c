#include <stdio.h>
#define MAX1 10

struct poly
{
    int coeff[10]; 
    int size;
}; 
typedef struct poly poly; 

void createpoly(poly *p)
{
    char choice; 
    printf("Do you want to add a term to the polynomial? (y/n): ");
    scanf(" %c", &choice);
    int count = 0; 
    while(choice != 'n' && choice != 'N' && count < MAX1)
    {
        if(choice != 'y' && choice != 'Y')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            printf("Do you want to add a term to the polynomial? (y/n): ");
            scanf(" %c", &choice);
            continue;
        }
        printf("Enter coefficient for x^%d: ", count);
        scanf("%d", &p->coeff[count]); 
        count++; 
        printf("Do you want to add a term to the polynomial? (y/n): ");
        scanf(" %c", &choice);
    } 
    if(count == MAX1)
    {
        printf("Maximum term limit reached. Cannot add more terms.\n");
    }
    for(int i = count; i < MAX1; i++)
    {
        p->coeff[i] = 0; 
    }
    p->size = count; 
}

void add(poly p1, poly p2, poly* p3)
{
    for(int i = 0; i < MAX1; i++)
    {
        p3->coeff[i] = p1.coeff[i] + p2.coeff[i]; 
    }
    p3->size = (p1.size > p2.size) ? p1.size : p2.size; 
}

void showpoly(poly p)
{
    for(int i = 0; i < p.size; i++)
    {
        if(p.coeff[i] != 0)
        {
            if(i == p.size - 1)
            {
                printf(" %dx^%d", p.coeff[i], i); 
            }
            else
            {
                printf("%dx^%d + ", p.coeff[i], i); 
            }
        }
    }
}

int main()
{
    printf("Create first polynomial:\n"); 
    poly p1; 
    createpoly(&p1); 
    printf("First polynomial: ");
    showpoly(p1);
    printf("\nCreate second polynomial:\n");
    poly p2; 
    createpoly(&p2);
    printf("Second polynomial: ");
    showpoly(p2);
    poly p3; 
    add(p1, p2, &p3); 
    printf("\nSum of polynomials: ");
    showpoly(p3);
    return 0;
}