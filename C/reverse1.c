#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000
#define EMPTY -1

struct stack
{
    char s[MAX_LEN];
    int top;
};
typedef struct stack stack;

void reverse(stack* stk, stack* new_stk)
{
    stack* new_stk = (stack*)malloc(sizeof(stack));
    for (int i = 0; i < stk->top; i++)
    {
        stk->top--;
        new_stk->top++;
        new_stk->s[new_stk->top] = stk->s[stk->top];
    }
}

void reset(stack* stk)
{
    stk->top = EMPTY;
}