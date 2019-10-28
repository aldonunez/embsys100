#include <stdint.h>
#include <ctype.h>

#define RCC_BASE    0x40023800
#define RCC_AHB1ENR (*(uint32_t*) (RCC_BASE + 0x30))

#define GPIOA_BASE  0x40020000
#define GPIOA_MODER (*(uint32_t*) (GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(uint32_t*) (GPIOA_BASE + 0x14))

const char sSpaceEncoding[] = "/";

const char* sCharEncodings[] =
{
    // 0..?
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
    "",
    "",
    "",
    "",
    "",
    "",

    // @..Z
    "",
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
};

volatile int counter;

void Wait(int units)
{
    for (int i = 0; i < units; i++)
    {
        counter = 0;
        
        while (counter < 250000)
        {
            counter++;
        }
    }
}

void EncodeCharLed(char c)
{
    int ch = toupper(c);
    const char* elemStr;
    
    if (ch < '0' || ch > 'Z')
    {
      elemStr = sSpaceEncoding;
    }
    else
    {
      elemStr = sCharEncodings[ch - '0'];
    }
    
    for (const char* elem = elemStr; *elem != '\0'; elem++)
    {
        switch (*elem)
        {
        case '.':
            // Turn on the LED.
            GPIOA_ODR |= 0x20;
            Wait(1);
            break;

        case '-':
            // Turn on the LED.
            GPIOA_ODR |= 0x20;
            Wait(3);
            break;

        default:
            Wait(1);
            break;
        }

        // Turn off the LED.
        GPIOA_ODR &= ~0x20;
        Wait(1);
    }
}

void EncodeStringLed(char* s)
{
    for (; *s != '\0'; s++)
    {
        EncodeCharLed(*s);
        Wait(2);
    }
}

void main()
{
    // Enable the clock to peripheral AHB1 with RCC.
    RCC_AHB1ENR |= 1;

    // Set GPIO5 to output mode.
    GPIOA_MODER |= 0x400;

    // Turn off the LED.
    GPIOA_ODR &= ~0x20;

    char str[] = "ALDO ";

    while (1)
    {
        EncodeStringLed(str);
    }
}
