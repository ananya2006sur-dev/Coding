#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    double x;
    double y;
};
typedef struct point point;

point p1 = {4, 4.0};
point* ptr = &p1;

int main()
{
    printf("%f", p1.x);
}