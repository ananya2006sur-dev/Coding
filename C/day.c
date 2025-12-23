#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum day {Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7};
typedef enum day day;
enum month {January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12};
typedef enum month month;

char* dayname(day d)
{
    switch (d)
    {
        case Monday: return "Monday"; break;
        case Tuesday: return "Tuesday"; break;
        case Wednesday: return "Wednesday"; break;
        case Thursday: return "Thursday"; break;
        case Friday: return "Friday"; break;
        case Saturday: return "Saturday"; break;
        case Sunday: return "Sunday"; break;
        default: return "Invalid day"; break;
    }
}

char* monthname(month m)
{
    switch (m)
    {
        case January: return "January"; break;
        case February: return "February"; break;
        case March: return "March"; break;
        case April: return "April"; break;
        case May: return "May"; break;
        case June: return "June"; break;
        case July: return "July"; break;
        case August: return "August"; break;
        case September: return "September"; break;
        case October: return "October"; break;
        case November: return "November"; break;
        case December: return "December"; break;
        default: return "Invalid month"; break;
    }
}

int main()
{
    day today;
    month this_month;
    printf("Enter today's day: ");
    scanf("%d", &today);
    printf("Enter this month: ");
    scanf("%d", &this_month);
    printf("Today is %s, %s\n", dayname(today), monthname(this_month));
} 
