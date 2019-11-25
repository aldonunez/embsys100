1. Swapping pointers.
    a.  The main function puts the integer values at SP+0xC and SP+8.
        Then it puts the values of SP+0xC and SP+8 at SP+4 and SP+0 (the pointers).
        Lastly it sets R0 and R1 to SP+4 and SP+0, the addresses of the pointers.
    b. R0 = 0x200003EC, R1 = 0x200003E8, SP = 0x200003E8

