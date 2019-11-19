#ifndef ALDO_STACK_H
#define ALDO_STACK_H

#include <stdbool.h>


void StackInit();
bool StackPush(int item);
bool StackPop(int* item);
bool StackEmpty();
bool StackFull();

#endif /* ALDO_STACK_H */
