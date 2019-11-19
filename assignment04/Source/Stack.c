#include "Stack.h"

/*
i. The stack should have a predefined size
ii. The stack supports “int” data types.
iii. Provide a function to initialize the stack internals.
iv. Provide a function to push an element onto the stack
v. Provide a function to pop an element off the stack.
vi. Provide a function that returns 1 if stack is empty.
vii. Provide a function that returns 1 if stack is full
*/

#define STACK_SIZE  3


static int gStack[STACK_SIZE];
static int gTop;


void StackInit()
{
    gTop = 0;
}

bool StackPush(int item)
{
    if (gTop == STACK_SIZE)
        return false;

    gStack[gTop] = item;
    gTop++;

    return true;
}

bool StackPop(int* item)
{
    if (gTop == 0)
        return false;

    gTop--;
    *item = gStack[gTop];

    return true;
}

bool StackEmpty()
{
    return gTop == 0;
}

bool StackFull()
{
    return gTop == STACK_SIZE;
}
