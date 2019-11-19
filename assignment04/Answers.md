1. Bit-banding
    b. Instructions with bit-banding

        0x800'0066: 0x4a0b         LDR.N     R2, [PC, #0x2c]  ; 0x4240'0294
        0x800'0068: 0x2301         MOVS      R3, #1
        0x800'006a: 0x6013         STR       R3, [R2]

    c. Instructions without bit-banding
    
        0x800'0066: 0x4a0d         LDR.N     R2, [PC, #0x34]  ; GPIOA_ODR
        0x800'0068: 0x6813         LDR       R3, [R2]
        0x800'006a: 0xf053 0x0320  ORRS.W    R3, R3, #32             ; 0x20
        0x800'006e: 0x6013         STR       R3, [R2]

2. Calling convention
    a. The first four arguments are passed by register. The rest are pushed onto the stack.
    b. Extra instructions in the caller:

        ; Save LR for return.
        ; Push a dummy value, to save space for 5th argument to Callee.
        0x800'00bc: 0xb580         PUSH      {R7, LR}
        ; Put 5th argument on the stack at SP.
        0x800'00be: 0x2038         MOVS      R0, #56                 ; 0x38
        0x800'00c0: 0x9000         STR       R0, [SP]

    c. Extra instructions in the callee:
    
        ; Save ABI mandated register R4, which we use.
        0x800'00ac: 0xb410         PUSH      {R4}
        ; Load the 5th argument right above our stack frame.
        0x800'00ae: 0x9c01         LDR       R4, [SP, #0x4]

    d. Other observations. Even when arguments don't spill onto the stack, a caller pushes a dummy value onto the stack. I don't understand this. For example:
    
        CallerNoSpill:
        0x800'00d4: 0xb580         PUSH      {R7, LR}
        0x800'00d6: 0x2117         MOVS      R1, #23            ; 0x17
        0x800'00d8: 0x200c         MOVS      R0, #12            ; 0xc
        0x800'00da: 0xf7ff 0xfff9  BL        CalleeNoSpill      ; 0x800'00d0
        0x800'00de: 0xbd02         POP       {R1, PC}

