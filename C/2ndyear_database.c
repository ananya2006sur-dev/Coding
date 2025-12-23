#include <stdio.h>
#define MAX1 10
#define MAX2 5 
#include <string.h>
#include <stdlib.h>

struct Student
{
    int roll_no; 
    char name[MAX1];
    int de; 
    int dsa; 
    int eca; 
    int total; 
    float average; 
};
typedef struct Student Student; 

void display(Student students[MAX2], int count)
{
    if(count == 0)
    {
        printf("No student records to display.\n");
        return;
    }
    printf("Roll No\tName\tDE\tDSA\tECA\tTotal\tAverage\n"); 
    for(int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", students[i].roll_no, students[i].name, students[i].de, students[i].dsa, students[i].eca, students[i].total, students[i].average); 
    }
}

void modify(Student students[MAX2], int count, char choice[10], int rno)
{
    int i;
    for(i = 0; i < count; i++)
    {
        if(students[i].roll_no == rno)
        {
            printf("Student with roll no %dfound.\n", rno); 
            break; 
        }
    }
    if(i == count)
    {
        printf("Student with roll no %d not found.\n", rno); 
        return; 
    }
    if(strcmp(choice, "rollno") == 0)
    {
        printf("Enter new roll number: "); 
        scanf("%d", &students[i].roll_no);
    }
    else if(strcmp(choice, "name") == 0)
    {
        printf("Enter new name: "); 
        scanf("%s", students[i].name); 
    }
    else if(strcmp(choice, "de") == 0)
    {
        printf("Enter new DE marks: "); 
        scanf("%d", &students[i].de);
        students[i].total = students[i].de + students[i].dsa + students[i].eca;
        students[i].average = students[i].total / 3.0;
    }
    else if(strcmp(choice, "dsa") == 0)
    {
        printf("Enter new DSA marks: "); 
        scanf("%d", &students[i].dsa);
        students[i].total = students[i].de + students[i].dsa + students[i].eca;
        students[i].average = students[i].total / 3.0;
    }
    else if(strcmp(choice, "eca") == 0)
    {
        printf("Enter new ECA marks: "); 
        scanf("%d", &students[i].eca);
        students[i].total = students[i].de + students[i].dsa + students[i].eca;
        students[i].average = students[i].total / 3.0;
    }
    else
    {
        printf("Invalid choice for modification.\n"); 
        return; 
    }
}

void append(Student students[MAX2], int new_rno, char new_name[MAX1], int new_de, int new_dsa, int new_eca, int *count)
{
    if(*count >= MAX2)
    {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    students[*count].roll_no = new_rno; 
    strcpy(students[*count].name, new_name); 
    students[*count].de = new_de;
    students[*count].dsa = new_dsa;
    students[*count].eca = new_eca;
    students[*count].total = new_de + new_dsa + new_eca;
    students[*count].average = students[*count].total / 3.0;
    (*count)++;
} 

void search(Student students[MAX2], int count, int rno)
{
    int i; 
    for(i = 0; i < count; i++)
    {
        if(students[i].roll_no == rno)
        {
            printf("Student found:\n"); 
            break; 
        }
    }
    if(i == count)
    {
        printf("Student with roll no %d not found.\n", rno);
        return; 
    }
    printf("Roll No\tName\tDE\tDSA\tECA\tTotal\tAverage\n");
    printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", students[i].roll_no, students[i].name, students[i].de, students[i].dsa, students[i].eca, students[i].total, students[i].average); 
}

void sort(Student students[MAX2], int count)
{
    int i, j; 
    Student temp; 
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(students[j].roll_no > students[j + 1].roll_no)
            {
                temp = students[j]; 
                students[j] = students[j + 1]; 
                students[j + 1] = temp;
            }
        }
    }
    printf("Records sorted by roll number.\n");
}

int main()
{
    Student students[MAX2]; 
    int count = 0; 
    char choice; 
    printf("Do you want to add a new student record? (y/n): ");
    scanf(" %c", &choice);
    while(choice != 'n' && choice != 'N' && count < MAX2)
    {
        if(choice != 'y' && choice != 'Y')
        {
            printf("Invalid choice. Please enter 'y' or 'n'(in capital or small).\n");
            printf("Do you want to add a new student record? (y/n): ");
            scanf(" %c", &choice);
            continue;
        }
        printf("Enter roll number: ");
        int rno;
        scanf("%d", &rno);
        printf("Enter name: ");
        char name[MAX1];
        scanf("%s", name);
        printf("Enter DE marks: ");
        int de;
        scanf("%d", &de);
        printf("Enter DSA marks: ");
        int dsa;
        scanf("%d", &dsa);
        printf("Enter ECA marks: ");
        int eca;
        scanf("%d", &eca);
        append(students, rno, name, de, dsa, eca, &count);
        printf("Do you want to add a new student record? (y/n): ");
        scanf(" %c", &choice);
    }
    if(count == MAX2)
    {
        printf("Maximum student limit reached. Cannot add more records.\n");
    }
    printf("Which operation do you want to perform?\n");
    printf("1. Display all records\n");
    printf("2. Modify a record\n");
    printf("3. Search for a record\n");
    printf("4. Sort records by roll number\n");
    printf("Enter your choice (1-4): ");
    int op_choice;
    scanf("%d", &op_choice);
    do
    {
        switch(op_choice)
        {
            case 1:
                display(students, count);
                break;
            case 2:
                if(count == 0)
                {
                    printf("No student records to modify.\n");
                    break;
                }
                char mod_choice[10];
                int rno;
                printf("Enter roll number of the student to modify: ");
                scanf("%d", &rno);
                printf("Enter the field to modify (rollno/name/de/dsa/eca): ");
                scanf("%s", mod_choice);
                modify(students, count, mod_choice, rno);
                break;
            
            case 3:
                if(count == 0)
                {
                    printf("No student records to search.\n");
                    break;
                }
                printf("Enter roll number of the student to search: ");
                scanf("%d", &rno);
                search(students, count, rno);
                break;
            
            case 4:
                if(count == 0)
                {
                    printf("No student records to sort.\n");
                    break;
                }
                sort(students, count);
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &op_choice);
                continue;
        }
        
            printf("Do you want to perform another operation? (y/n): ");
            scanf(" %c", &choice);
            do
            {
                if(choice == 'y' || choice == 'Y')
                {
                    printf("Enter your choice (1-4): ");
                    scanf("%d", &op_choice);
                    break; 
                }
                else if(choice == 'n' || choice == 'N')
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
            } while (1);  
    } while(1); 
    return 0;
}
