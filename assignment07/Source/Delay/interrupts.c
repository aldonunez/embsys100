#include <stdint.h>
#include <stdlib.h>
#include "stm32f401xe.h"


#if 1

extern void* CSTACK$$Limit;
extern void* __iar_program_start;

void DefaultHandler(void);
void SysTickHandler(void);


void* const __vector_table[] @ ".intvec" =
{
    &CSTACK$$Limit,
    &__iar_program_start,

    (void*) DefaultHandler,     // NMI
    (void*) DefaultHandler,     // Hard fault
    (void*) DefaultHandler,     // Memory management fault
    (void*) DefaultHandler,     // Bus fault
    (void*) DefaultHandler,     // Usage fault

    (void*) DefaultHandler,     // Reserved
    (void*) DefaultHandler,     // Reserved
    (void*) DefaultHandler,     // Reserved
    (void*) DefaultHandler,     // Reserved

    (void*) DefaultHandler,     // SVCall
    (void*) DefaultHandler,     // Reserved for debug
    (void*) DefaultHandler,     // Reserved
    (void*) DefaultHandler,     // PendSV

    (void*) SysTickHandler,     // SysTick
};


void DefaultHandler()
{
    while (1)
    {
    }
}

volatile uint32_t counter;

void SysTickHandler()
{
    if (counter > 0)
        counter--;
}

#endif
