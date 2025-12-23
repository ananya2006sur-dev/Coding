#include <stdio.h>

int main(int argc, char** argv)
{
    typedef struct Student Stud;
    struct Student
    {
        int number;
        float percent;
        char grade;
    };

    Stud student0 = {10101010, 89.5, 'B'};
    printf("Student number: %d\n", student0.number);
}