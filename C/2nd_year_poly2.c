#include <stdio.h>
#define MAX1 10

struct term
{
    int coeff;
    int power; 
}; 
typedef struct term term; 

struct poly
{
    term terms[MAX1]; 
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
        printf("Enter coefficient: "); 
        scanf("%d", &p->terms[count].coeff);  
        printf("Enter power: ");
        scanf("%d", &p->terms[count].power);
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
        p->terms[i].coeff = 0; 
        p->terms[i].power = -1; 
    }
    p->size = count; 
}

void sort(poly *p)
{
    term temp;
    for(int i = 0; i < p->size - 1; i++)
    {
        for(int j = 0; j < p->size - i - 1; j++)
        {
            if(p->terms[j].power < p->terms[j + 1].power)
            {
                temp = p->terms[j]; 
                p->terms[j] = p->terms[j + 1]; 
                p->terms[j + 1] = temp; 
            }
        }
    }
}

void add(poly p1, poly p2, poly* p3)
{
    int i, j, k; 
    i = 0; 
    j = 0; 
    k = 0; 
    while((i < p1.size || j < p2.size) && k < MAX1)
    {
        if(p1.terms[i].power == p2.terms[j].power)
        {
            p3->terms[k].power = p1.terms[i].power;
            p3->terms[k].coeff = p1.terms[i].coeff + p2.terms[j].coeff; 
            i++;
            j++; 
        }
        else if(p1.terms[i].power > p2.terms[j].power)
        {
            p3->terms[k] = p1.terms[i];
            i++; 
        }
        else
        {
            p3->terms[k] = p2.terms[j];
            j++; 
        }
        k++; 
    }
    p3->size = k;
}

void showpoly(poly p)
{
    for(int i = 0; i < p.size; i++)
    {
        if(p.terms[i].coeff != 0)
        {
            if(i == p.size - 1)
            {
                printf(" %dx^%d", p.terms[i].coeff, p.terms[i].power); 
            }
            else
            {
                printf("%dx^%d + ", p.terms[i].coeff, p.terms[i].power); 
            }
        }
    }
}

int main()
{
    printf("Create first polynomial:\n"); 
    poly p1; 
    createpoly(&p1); 
    sort(&p1);
    printf("First polynomial: ");
    showpoly(p1);
    printf("\nCreate second polynomial:\n");
    poly p2; 
    createpoly(&p2);
    sort(&p2);
    printf("Second polynomial: ");
    showpoly(p2);
    poly p3; 
    add(p1, p2, &p3); 
    printf("\nSum of polynomials: ");
    showpoly(p3);
    return 0;
}