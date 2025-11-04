; filepath: /home/vasan/Desktop/SYSTEM_PROJECT/CUSTOM_CPU/programs/arithmetic_test.asm
; Test ADD, SUB, INC, DEC properly

; Data section
@200 10
@201 5
@202 20

; Program
LOAD R0, 200    ; R0 = 10
LOAD R1, 201    ; R1 = 5
LOAD R3, 202    ; R3 = 20

; Test ADD (accumulation)
ADD R2, R0      ; R2 = 0 + 10 = 10
ADD R2, R1      ; R2 = 10 + 5 = 15

; Test SUB (reduction)
SUB R3, R0      ; R3 = 20 - 10 = 10
SUB R3, R1      ; R3 = 10 - 5 = 5

; Test INC/DEC
INC R0          ; R0 = 11
DEC R1          ; R1 = 4

HALT

; Expected:
; R0 = 11
; R1 = 4
; R2 = 15
; R3 = 5