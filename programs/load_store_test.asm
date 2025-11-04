; filepath: /home/vasan/Desktop/SYSTEM_PROJECT/CUSTOM_CPU/programs/load_store_test.asm
; Test basic LOAD and STORE operations

; Data section
@200 42
@201 99

; Program
LOAD R0, 200    ; Load 42 into R0
LOAD R1, 201    ; Load 99 into R1
STORE R0, 100   ; Store R0 (42) to mem[100]
STORE R1, 101   ; Store R1 (99) to mem[101]
HALT

; Expected:
; R0 = 42
; R1 = 99
; mem[100] = 42
; mem[101] = 99