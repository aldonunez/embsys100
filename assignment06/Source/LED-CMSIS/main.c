#include "stm32f401xe.h"


volatile int counter;

void delay(uint32_t ticks)
{
    counter = 0;
    while (counter < ticks)
    {
      counter++;
    }
}

int main()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    while (1)
    {
        delay(1000000);
        GPIOA->ODR ^= GPIO_ODR_OD5;
    }

    return 0;
}
