# Simple Custom CPU

A minimalist, 8-bit CPU designed for educational and system software learning purposes. This processor uses a Von Neumann architecture for unified memory and simple instruction handling.

## Features

- **Von Neumann architecture**: Instructions and data reside in the same memory space.
- **256 bytes unified memory**: Byte-addressable, accessible using 8-bit addresses.
- **Registers**:
  - Four 8-bit general purpose (R0, R1, R2, R3)
  - Program Counter (PC), Instruction Register (IR)
  - Flag Register (Zero flag for conditional operations)
- **ALU Operations**:
  - Addition, Subtraction
  - Bitwise AND, OR, XOR
  - Increment, Decrement
  - Updates Zero flag
- **Control Unit**:
  - Generates control signals for CPU operations
  - Handles instruction fetch, decode, execute, PC updates
- **16-instruction set** (encoded in 16 bits):
  - NOP, LOAD, STORE, ADD, SUB, AND, OR, XOR, JUMP, JZ, INC, DEC, MOV, HALT, etc.

## Instruction Set

| Mnemonic | Description              | Syntax                |
| -------- | ------------------------ | --------------------- |
| NOP      | No operation             | NOP                   |
| LOAD     | Load memory to register  | LOAD Rdest, address   |
| STORE    | Store register to memory | STORE Rsrc, address   |
| ADD      | Add registers            | ADD Rdest, Rsrc       |
| SUB      | Subtract registers       | SUB Rdest, Rsrc       |
| AND      | Bitwise AND              | AND Rdest, Rsrc       |
| OR       | Bitwise OR               | OR Rdest, Rsrc        |
| XOR      | Bitwise XOR              | XOR Rdest, Rsrc       |
| JUMP     | Unconditional jump       | JUMP address          |
| JZ       | Jump if zero flag set    | JZ address            |
| INC      | Increment register       | INC Rdest             |
| DEC      | Decrement register       | DEC Rdest             |
| MOV      | Move between registers   | MOV Rdest, Rsrc       |
| HALT     | Stop CPU execution       | HALT                  |

## CPU Operation Cycle

1. **Fetch**: PC points to next instruction; instruction loaded to IR.
2. **Decode**: CPU interprets opcode and operands.
3. **Execute**: ALU or memory performs the operation; data movement as needed.
4. **Write-back**: Result is stored in register or memory.
5. **Repeat**: Continues per clock cycle until HALT.

## Usage

- Load binary program and data into memory.
- Reset PC to start address.
- Run clock cycles or single-step through instructions.
- Monitor registers and memory for output/debug.

## License

This project is open for educational, non-commercial use.

---

