1. Signed counter starts at 0x7FFFFFFF.
  a. counter = -2147483648
  b. R1 = 0x80000000
  c. APSR.NV <> 0, because:
    * N = 1, because the high bit of 0x80000000 is 1
    * V = 1, because the value wrapped from positive to negative
2. Signed counter starts at 0xFFFFFFFF.
  a. counter becomes 0
  b. APSR.NV = 0, because:
    * N = 0, because the high bit of 0x00000000 is 0
    * V = 0, because the value went from negative to positive; no overflow.
3. Unsigned counter starts at 0x7FFFFFFF.
  a. counter = 2147483648
  b. R1 = 0x80000000
  c. APSR.NV <> 0, because:
    * N = 1, because the high bit of 0x80000000 is 1
    * V = 1, because the value wrapped from positive to negative.
      Even though the variable in C is unsigned, the processor doesn't know
      that. It treats the fact that the register went from a value that could
      be interpreted as positive to one that could be interpreted as negative
      as signed overflow.
4. Unsigned counter starts at 0xFFFFFFFF.
  a. counter becomes 0
  b. APSR.NV = 0, because:
    * N = 0, because the high bit of 0x00000000 is 0
    * V = 0, because the value went from negative to positive; no overflow.
      Even though the variable in C is unsigned, the processor doesn't know
      that. It treats the fact that the register went from a value that could
      be interpreted as positive to one that could be interpreted as negative
      as signed overflow.
5. Global counter.
  a. The scope of counter is global.
  b. counter no longer shows up in the Locals pane.
  c. counter can be found in the Statics pane, because it has static lifetime;
     and in the Autos pane, because there is a reference to counter in the
     current line.
  d. The location of counter is 0x20000000 in the address space.
6. Pointer on simulator.
  a. The value of counter is 4 at the end.
  b. counter started at 0 and was incremented 4 times by 4 statements. Three of
     them referenced p_int which points to counter. p_int points to counter,
     because it was set to counter's address explicitly.
7. Pointer on physical device.
  a. The location of counter is 0x20000000 in the address space.
  b. Because counter is an ordinary static, it must be in RAM.
  c. The value of counter is 4 at the end.

