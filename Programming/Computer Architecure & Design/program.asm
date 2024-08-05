ORG 0000H
MVI A, 3AH    ; Initialize memory location 2000H with value 3AH
STA 2000H
LDA 2000H     ; Load the value from memory location 2000H into the accumulator
STA 2001H     ; Store the value from the accumulator into memory location 2001H
HLT           ; Halt the processor