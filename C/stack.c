#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

struct stack
{
    char s[MAX_LEN];
    int top;
};
typedef struct stack stack;

void push(char c, stack* stk)
{
    stk->top++;
    stk->s[stk->top] = c;
}

void pop(stack* stk)
{
    stk->top--;
}
