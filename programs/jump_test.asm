; filepath: /home/vasan/Desktop/SYSTEM_PROJECT/CUSTOM_CPU/programs/jump_test.asm
; Test JUMP instruction

; Data section
@200 1
@201 2
@202 3

; Program starts at address 0
LOAD R0, 200    ; Address 0-1: R0 = 1
JUMP 6          ; Address 2-3: Jump to address 6 (skip LOAD R1)
LOAD R1, 201    ; Address 4-5: This should be SKIPPED
LOAD R2, 202    ; Address 6-7: R2 = 3 (JUMP lands here)
HALT            ; Address 8-9

; Expected:
; R0 = 1
; R1 = 0 (not loaded - skipped)
; R2 = 3 (loaded after jump)