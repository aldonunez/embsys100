/*******************************************************************************
File name       : div2Asm.s
Description     : Assembly language function for division by 2
*******************************************************************************/

/*
a. Write the assembly code to take an input argument, divide it by 2, and return the result.
b. Invoke the function “PrintString” from within divAsm before doing the division
computation.
c. Add a comment for every statement in your assembly function code.
d. In the main.c, invoke dev2Asm(foo) and capture the screen output from TeraTerm.
*/

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.

    PUBLIC div2Asm      // Exports symbols to other modules
                        // Making div2Asm available to other modules.

    SECTION .text:CODE:REORDER:NOROOT(2)

    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions

/*******************************************************************************
Function Name   : div2Asm
Description     : Calls C code to print a string;
                  divides its input argument in half
C Prototype     : int div2Asm(int val)
                : Where val is the value to divide
Parameters      : R0: val
Return value    : R0
*******************************************************************************/

div2Asm
    PUSH {R0,LR}        // save the input argument and return address
    LDR R0,=myCstr      // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0,LR}         // Restore R0 and LR
    MOV R0, R0, ASR #1  // Shift right by one to divide by two.
                        // Make it arithmetic, because the input is signed.
    BX LR               // return (with function result in R0)

    END
