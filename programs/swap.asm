; Swap mem[200] and mem[201]

; Program
LOAD R0, 200    ; R0 = mem[200] (e.g., 7)
LOAD R1, 201    ; R1 = mem[201] (e.g., 18)
STORE R0, 201   ; mem[201] = old mem[200] (7)
STORE R1, 200   ; mem[200] = old mem[201] (18)
HALT

; Data (example values to swap)
@200 7
@201 18

; Expected after HALT:
; mem[200] = 18
; mem[201] = 7
; R0 = 7, R1 = 18