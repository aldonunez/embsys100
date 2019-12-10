#include <stdint.h>
#include "stm32f401xe.h"


void main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    // Start with the LED on. Then wait.
    GPIOA->ODR ^= GPIO_ODR_OD5;

    // 16 million fits in 24 bits.
    // The device's default CPU frequency is 16 MHz.
    // So, we'll get a sys-tick once a second.

    SysTick->LOAD = 15'999'999;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;

    while (1)
    {
    }
}
