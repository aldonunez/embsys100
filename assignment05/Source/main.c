/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.


Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

int sqrAsm(int val);
int div2Asm(int val);
int swapCharsAsm(char* a, char* b);
const char* myCstr = "";

/*******************************************************************************
Function Name   : main
Description     :
Parameters      :
Return value    :               */
void main() {
  uint8_t foo;
  int ret;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("Aldo's Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));

  myCstr = "Hello from sqrAsm\r\n\r\n";
  sqrAsm(3);

  myCstr = "Hello from div2Asm(97)\r\n";
  ret = div2Asm(97);
  RETAILMSG(1, ("div2Asm returned %d\r\n\r\n", ret));

  char c1;
  char c2;

  c1 = 'x';
  c2 = 'y';
  myCstr = "Hello from swapCharsAsm(c1='x', c2='y')\r\n";
  ret = swapCharsAsm(&c1, &c2);
  RETAILMSG(1, ("swapCharsAsm returned %d, c1='%c', c2='%c'\r\n\r\n", ret, c1, c2));

  c1 = 'z';
  c2 = 'z';
  myCstr = "Hello from swapCharsAsm(c1='z', c2='z')\r\n";
  ret = swapCharsAsm(&c1, &c2);
  RETAILMSG(1, ("swapCharsAsm returned %d, c1='%c', c2='%c'\r\n\r\n", ret, c1, c2));

  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");

    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);

    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {

  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
