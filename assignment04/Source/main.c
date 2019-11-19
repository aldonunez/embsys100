#include "Stack.h"
#include <assert.h>
#include <stdint.h>


/*
4. Bonus: Using the power of pointers and type casting, create a function that can determine if a
computer is big-endian or little-endian. Test your function in the simulator and modify the
Project Options (as shown in the figure below) against:
  a. Device STM32F401RE
  b. Cortex M4 (Little endian option)
  c. Cortex M4 (Big Endian option)
*/

// Return zero if little endian; non-zero if big endian.
int GetEndian()
{
    uint32_t memValue = 0x12345678;

    return *(uint8_t*) &memValue == 0x12;
}

void TestEndian()
{
    assert(GetEndian() != 0);
}

void TestStack()
{
    int item;

    //------------------------------------------------------------------------
    // Empty

    StackInit();
    assert(StackEmpty());
    assert(!StackFull());
    assert(!StackPop(&item));

    //------------------------------------------------------------------------
    // Add one

    StackInit();
    assert(StackPush(99));
    assert(!StackEmpty());
    assert(!StackFull());
    assert(StackPop(&item));
    assert(item == 99);
    assert(StackEmpty());

    //------------------------------------------------------------------------
    // Fill, then empty

    StackInit();

    assert(StackPush(1));
    assert(!StackEmpty());
    assert(!StackFull());

    assert(StackPush(2));
    assert(!StackEmpty());
    assert(!StackFull());

    assert(StackPush(3));
    assert(!StackEmpty());
    assert(StackFull());

    assert(StackPop(&item));
    assert(item == 3);
    assert(!StackEmpty());
    assert(!StackFull());

    assert(StackPop(&item));
    assert(item == 2);
    assert(!StackEmpty());
    assert(!StackFull());

    assert(StackPop(&item));
    assert(item == 1);
    assert(StackEmpty());
    assert(!StackFull());

    //------------------------------------------------------------------------
    // Try to overflow

    StackInit();
    assert(StackPush(4));
    assert(StackPush(5));
    assert(StackPush(6));
    assert(!StackPush(7));

    // Still OK?

    assert(StackFull());
    assert(StackPop(&item));
    assert(item == 6);
    assert(StackPop(&item));
    assert(item == 5);
    assert(StackPop(&item));
    assert(item == 4);
    assert(StackEmpty());

    //------------------------------------------------------------------------
    // Mixed pushing and popping

    StackInit();

    // +2, -1, +2, -1, +1, -2, -1
    // 12  1   134 13  135 1

    assert(StackPush(1));
    assert(StackPush(2));
    assert(StackPop(&item));
    assert(item == 2);

    assert(StackPush(3));
    assert(StackPush(4));
    assert(StackPop(&item));
    assert(item == 4);

    assert(StackPush(5));
    assert(StackPop(&item));
    assert(item == 5);
    assert(StackPop(&item));
    assert(item == 3);

    assert(StackPop(&item));
    assert(item == 1);
    assert(StackEmpty());

    //------------------------------------------------------------------------
    // Fill and empty twice

    StackInit();

    assert(StackPush(10));
    assert(StackPush(11));
    assert(StackPush(12));
    assert(StackFull());

    assert(StackPop(&item));
    assert(item == 12);
    assert(StackPop(&item));
    assert(item == 11);
    assert(StackPop(&item));
    assert(item == 10);
    assert(StackEmpty());

    // Again

    assert(StackPush(33));
    assert(StackPush(44));
    assert(StackPush(55));
    assert(StackFull());

    assert(StackPop(&item));
    assert(item == 55);
    assert(StackPop(&item));
    assert(item == 44);
    assert(StackPop(&item));
    assert(item == 33);
    assert(StackEmpty());
}

int main()
{
    TestEndian();
    TestStack();

    return 0;
}
