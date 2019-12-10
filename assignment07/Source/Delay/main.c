#include <stdint.h>
#include "stm32f401xe.h"


#define DELAY_DURATION 2000
#define USE_SYSTICK_INTERRUPT


#if defined(USE_SYSTICK_INTERRUPT)

extern volatile uint32_t counter;

void delay(uint32_t milliseconds)
{
    // Load the target time. Stop waiting when it reaches zero.
    counter = milliseconds;

    // The device's default CPU frequency is 16 MHz.
    // Use 16,000, so that we'll get a sys-tick once a millisecond.

    SysTick->LOAD = 15'999;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;

    while (counter > 0)
    {
    }

    // Turn off the timer.
    SysTick->CTRL = 0;
}

#else

void delay(uint32_t milliseconds)
{
    // The device's default CPU frequency is 16 MHz.
    // Use 16,000, so that we'll get a sys-tick once a millisecond.

    SysTick->LOAD = 15'999;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_ENABLE_Msk;

    for (uint32_t t = 0; t < milliseconds; t++)
    {
        // When COUNTFLAG is set, SysTick->VAL has reached 0.
        // So, we've waited a millisecond.
        // COUNTFLAG is reset automatically when you read it.

        while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0)
        {
        }
    }

    // Turn off the timer.
    SysTick->CTRL = 0;
}

#endif


void main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    while (1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;

        delay(DELAY_DURATION);
    }
}
