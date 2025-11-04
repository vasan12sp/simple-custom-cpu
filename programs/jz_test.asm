; filepath: /home/vasan/Desktop/SYSTEM_PROJECT/CUSTOM_CPU/programs/jz_test.asm
; Test JZ instruction

; Data section
@200 0
@201 99
@202 5

; Program
LOAD R0, 200    ; Address 0-1: R0 = 0 (zero)
JZ 6            ; Address 2-3: Jump to address 6 (skip LOAD R1)
LOAD R1, 201    ; Address 4-5: This should be SKIPPED (R1 stays 0)
LOAD R2, 202    ; Address 6-7: R2 = 5 (JZ lands here) ✅
HALT            ; Address 8-9

; Expected:
; R0 = 0
; R1 = 0 (not loaded - skipped by JZ)
; R2 = 5 (loaded after jump)