/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for division by 2
*******************************************************************************/

/*
a. It takes as input two variables of char data type and swaps the two chars
b. Add a comment for every statement in your assembly function code.
c. Bonus: Returns 0 if the two chars are identical; otherwise, return 1.
*/

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.

    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.

    SECTION .text:CODE:REORDER:NOROOT(2)

    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions

/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string;
                  divides its input argument in half
C Prototype     : int swapCharsAsm(char* a, char* b)
                : Where val is the value to divide
Parameters      : R0: a
                  R1: b
Return value    : R0
*******************************************************************************/

swapCharsAsm
    PUSH {R0,R1,LR}     // save the input arguments and return address
    LDR R0,=myCstr      // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0,R1,LR}      // Restore R0, R1, and LR
    LDRB R2, [R0]       // Get the original value at pointer a into R2
    LDRB R3, [R1]       // Get the original value at pointer b into R3
    STRB R3, [R0]       // Set value at pointer a to value from pointer b in R3
    STRB R2, [R1]       // Set value at pointer b to value from pointer a in R2
    SUBS R0, R2, R3     // Subtract the two chars.
                        // If they are, then R0 will be 0, and Z/EQ will be set.
    IT NE               // Otherwise, Z/EQ will be clear.
    MOVNE R0, #1        // So, put 1 in R0.
    BX LR               // return (with function result in R0)

    END
