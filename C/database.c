#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000 

struct student {
    int rollno;
    char name[MAX_SIZE]; 
    float DE, DSA, ECA, total, average; 
}; 
typedef struct student student; 


void display(student s[MAX_SIZE], int n) {
    printf("RollNo\tName\tDE Marks\tDSA Marks\tECA Marks\tTotal\tAverage\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%f\t%f\t%f\t%f\t%f\n",  
               s[i].rollno, s[i].name, s[i].DE, s[i].DSA, 
               s[i].ECA, s[i].total, s[i].average);
    } 
} 


void search(student s[MAX_SIZE], int rn, int n) {
    int i = 0, flag = 0; 
    while (i < n) {
        if (s[i].rollno == rn) {
            flag = 1; 
            printf("Student Found\n"); 
            break; 
        }
        i++; 
    }
    if (flag == 0) {
        printf("Student Not Found\n"); 
    } else {
        printf("Information of the student:\n"); 
        printf("RollNo\tName\tDE Marks\tDSA Marks\tECA Marks\tTotal\tAverage\n");
        printf("%d\t%s\t%f\t%f\t%f\t%f\t%f\n",
               s[i].rollno, s[i].name, s[i].DE, s[i].DSA,
               s[i].ECA, s[i].total, s[i].average);
    }
}


void append(student s[MAX_SIZE], int rn, char nm[MAX_SIZE], float de, float dsa, float eca, int *n) {
    s[*n].rollno = rn; 
    strcpy(s[*n].name, nm); 
    s[*n].DE = de; 
    s[*n].DSA = dsa;
    s[*n].ECA = eca; 
    s[*n].total = de + dsa + eca;
    s[*n].average = s[*n].total / 3.0;
    (*n)++; 
} 


void modify(student s[MAX_SIZE], int n, int rn, char ch[10], void *data) {
    int i = 0, flag = 0; 
    while (i < n) {
        if (s[i].rollno == rn) {
            flag = 1; 
            printf("Student Found\n"); 
            break; 
        }
        i++; 
    }
    if (flag == 0) {
        printf("Student Not Found\n"); 
        return;
    }

    if (strcmp(ch, "rollno") == 0) {
        s[i].rollno = *(int*)data; 
    }
    else if (strcmp(ch, "name") == 0) {
        strcpy(s[i].name, (char*)data); 
    }
    else if (strcmp(ch, "de") == 0) {
        s[i].DE = *(float*)data; 
    }
    else if (strcmp(ch, "dsa") == 0) {
        s[i].DSA = *(float*)data; 
    }
    else if (strcmp(ch, "eca") == 0) {
        s[i].ECA = *(float*)data; 
    }

    s[i].total   = s[i].DE + s[i].DSA + s[i].ECA;
    s[i].average = s[i].total / 3.0;
}	


void sort(student s[MAX_SIZE], int n, char ch[10]) {
    int i, j; 
    if (strcmp(ch, "rollno") == 0) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (s[i].rollno > s[j].rollno) {
                    student temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    }
    else if (strcmp(ch, "total") == 0) {
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (s[i].total > s[j].total) {
                    student temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    }			
}


int main() {
    int n;
    printf("Enter the no. of students: ");
    scanf("%d", &n);

    student info[MAX_SIZE];   
    for (int i = 1; i <= n; i++) {
        printf("Enter the details of the %dth student:\n", i); 
        printf("Roll No: ");
        scanf("%d", &info[i-1].rollno); 
        printf("Name: ");
        scanf("%s", info[i-1].name); 
        printf("Marks in DE: ");
        scanf("%f", &info[i-1].DE); 
        printf("Marks in DSA: ");
        scanf("%f", &info[i-1].DSA); 
        printf("Marks in ECA: "); 
        scanf("%f", &info[i-1].ECA); 
        info[i-1].total = info[i-1].DE + info[i-1].DSA + info[i-1].ECA; 
        info[i-1].average = info[i-1].total / 3.0; 
    } 

    search(info, 105, n); 
    append(info, 110, "Nikita", 84, 85, 86, &n); 
    int new_rollno = 171; 
    modify(info, n, 108, "rollno", &new_rollno); 
    sort(info, n, "total"); 
    display(info, n); 

    return 0; 
}