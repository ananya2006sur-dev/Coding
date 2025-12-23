/* A program to print a date legibly as well as its next day's date*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum month {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sept = 9, Oct = 10, Nov = 11, Dec = 12}; // Defining a data type month
typedef enum month month; // Defining a data type month

struct date // Defining a structure date
{
    int day; // Defining a member day of the structure date
    month monthnumber; // Defining a member monthnumber of the structure date
};
typedef struct date date;

char* monthname(month m) // Function to return the name of the month m
{
    switch (m)
    {
        case Jan: return "January"; break; 
        case Feb: return "February"; break;
        case Mar: return "March"; break;
        case Apr: return "April"; break;
        case May: return "May"; break;
        case Jun: return "June"; break;
        case Jul: return "July"; break;
        case Aug: return "August"; break;
        case Sept: return "September"; break;
        case Oct: return "October"; break;
        case Nov: return "November"; break;
        case Dec: return "December"; break;
    }
}

void nextday(date d) // Function to print the next day's date
{
    if (d.monthnumber == 1 || d.monthnumber == 3 || d.monthnumber == 5 || d.monthnumber == 7 || d.monthnumber == 8 || d.monthnumber == 10) // If the month has 31 days except December
    {
        if (d.day == 31) // If the day is the last day of the month
        {
            d.day = 1;
            d.monthnumber++;
        }
        else // If the day is not the last day of the month
        {
            d.day++;
        }
    }
    if (d.monthnumber == 4 || d.monthnumber == 6 || d.monthnumber == 9 || d.monthnumber == 11) // If the month has 30 days
    {
        if (d.day == 30) // If the day is the last day of the month
        {
            d.day = 1;
            d.monthnumber++;
        }
        else // If the day is not the last day of the month
        {
            d.day++;
        }
    }
    if (d.monthnumber == 2) // If the month is February (has 28 days)
    {
        if (d.day == 28) // If the day is the last day of the month
        {
            d.day = 1;
            d.monthnumber++;
        }
        else // If the day is not the last day of the month
        {
            d.day++;
        }
    }
    if (d.monthnumber == 12) // If the month is December (last month of the year)
    {
        if (d.day == 31) // If the day is the last day of the month
        {
            d.day = 1;
            d.monthnumber = 1;
        }
        else // If the day is not the last day of the month
        {
            d.day++;
        }
    }
    printf("Next day is %s %d\n", monthname(d.monthnumber), d.day); // Printing the next day's date in a legible format
}

void printdate(date d) // Function to print a date legibly
{
    printf("Date is %s %d\n", monthname(d.monthnumber), d.day); // Printing the date in a legible format
}

int main(void) // Providing five dates to the functions printdate and nextday 
{
    date d1;
    d1.day = 1;
    d1.monthnumber = 1;
    printdate(d1);
    nextday(d1);

    date d2;
    d2.day = 28;
    d2.monthnumber = 2;
    printdate(d2);
    nextday(d2);

    date d3;
    d3.day = 14;
    d3.monthnumber = 3;
    printdate(d3);
    nextday(d3);

    date d4;
    d4.day = 31;
    d4.monthnumber = 10;
    printdate(d4);
    nextday(d4);

    date d5;
    d5.day = 31;
    d5.monthnumber = 12;
    printdate(d5);
    nextday(d5);

    return 0;
}