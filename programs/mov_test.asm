; filepath: /home/vasan/Desktop/SYSTEM_PROJECT/CUSTOM_CPU/programs/mov_test.asm
; Test MOV (register copy)

; Data section
@200 77

; Program
LOAD R0, 200    ; R0 = 77
MOV R1, R0      ; R1 = R0 = 77
MOV R2, R1      ; R2 = R1 = 77
MOV R3, R2      ; R3 = R2 = 77
HALT

; Expected:
; R0 = 77
; R1 = 77
; R2 = 77
; R3 = 77