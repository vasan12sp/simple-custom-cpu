; test.asm - Simple addition program
; This program adds two numbers from memory and stores the result

; Load operands from memory
LOAD R0, 200          ; Load first number (5)
LOAD R1, 201          ; Load second number (10)

; Perform addition
ADD R2, R0            ; R2 = R2 + R0 = 0 + 5 = 5
ADD R2, R1            ; R2 = R2 + R1 = 5 + 10 = 15

; Store result
STORE R2, 100         ; Store result (15) to memory[100]

; Additional operations
INC R0                ; R0 = 5 + 1 = 6
SUB R3, R1            ; R3 = R3 - R1 = 0 - 10 = 246 (underflow)

; Stop execution
HALT

; Data section
@200 5                ; First operand = 5
@201 10               ; Second operand = 10
@100 0                ; Result location