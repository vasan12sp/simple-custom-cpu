#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_LINE 256
#define MEM_SIZE 256

// Opcode definitions
typedef enum {
    OP_NOP   = 0x0,
    OP_LOAD  = 0x1,
    OP_STORE = 0x2,
    OP_ADD   = 0x3,
    OP_SUB   = 0x4,
    OP_AND   = 0x5,
    OP_OR    = 0x6,
    OP_XOR   = 0xC,
    OP_JUMP  = 0x8,
    OP_JZ    = 0x9,
    OP_INC   = 0xA,
    OP_DEC   = 0xB,
    OP_MOV   = 0x7,
    OP_HALT  = 0xD
} Opcode;

// Register definitions
typedef enum {
    REG_R0 = 0,
    REG_R1 = 1,
    REG_R2 = 2,
    REG_R3 = 3
} Register;

// Global state
uint8_t memory[MEM_SIZE];
uint8_t memory_initialized[MEM_SIZE];  //  Track which addresses are set
int pc = 0;
int line_number = 0;

// Function prototypes
void error(const char *msg);
void trim(char *str);
int parse_register(const char *reg_str);
int parse_number(const char *num_str);
void encode_instruction(uint8_t opcode, uint8_t dest, uint8_t src, uint8_t imm);
void assemble_line(char *line);
void generate_verilog(const char *output_file);

// Error handling
void error(const char *msg) {
    fprintf(stderr, "Error on line %d: %s\n", line_number, msg);
    exit(1);
}

// Trim whitespace from string
void trim(char *str) {
    char *end;
    
    // Trim leading space
    while(isspace((unsigned char)*str)) str++;
    
    if(*str == 0) return;
    
    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

// Parse register name (R0, R1, R2, R3)
int parse_register(const char *reg_str) {
    if (strlen(reg_str) != 2 || toupper(reg_str[0]) != 'R') {
        error("Invalid register format");
    }
    
    int reg_num = reg_str[1] - '0';
    if (reg_num < 0 || reg_num > 3) {
        error("Register must be R0-R3");
    }
    
    return reg_num;
}

// Parse number (decimal or hexadecimal)
int parse_number(const char *num_str) {
    char *endptr;
    long value;
    
    if (strncmp(num_str, "0x", 2) == 0 || strncmp(num_str, "0X", 2) == 0) {
        value = strtol(num_str + 2, &endptr, 16);
    } else {
        value = strtol(num_str, &endptr, 10);
    }
    
    if (*endptr != '\0') {
        error("Invalid number format");
    }
    
    if (value < 0 || value > 255) {
        error("Number out of range (0-255)");
    }
    
    return (int)value;
}

// Encode instruction into memory
void encode_instruction(uint8_t opcode, uint8_t dest, uint8_t src, uint8_t imm) {
    if (pc >= MEM_SIZE - 1) {
        error("Program too large for memory");
    }
    
    // Instruction format: [15:12]=opcode, [11:10]=dest, [9:8]=src, [7:0]=imm
    uint8_t high_byte = (opcode << 4) | (dest << 2) | src;
    uint8_t low_byte = imm;
    
    memory[pc] = high_byte;
    memory_initialized[pc] = 1;  //Mark as initialized
    pc++;
    
    memory[pc] = low_byte;
    memory_initialized[pc] = 1;  // Mark as initialized
    pc++;
}

// Get opcode from mnemonic
int get_opcode(const char *mnemonic) {
    if (strcmp(mnemonic, "NOP") == 0) return OP_NOP;
    if (strcmp(mnemonic, "LOAD") == 0) return OP_LOAD;
    if (strcmp(mnemonic, "STORE") == 0) return OP_STORE;
    if (strcmp(mnemonic, "ADD") == 0) return OP_ADD;
    if (strcmp(mnemonic, "SUB") == 0) return OP_SUB;
    if (strcmp(mnemonic, "AND") == 0) return OP_AND;
    if (strcmp(mnemonic, "OR") == 0) return OP_OR;
    if (strcmp(mnemonic, "XOR") == 0) return OP_XOR;
    if (strcmp(mnemonic, "JUMP") == 0) return OP_JUMP;
    if (strcmp(mnemonic, "JZ") == 0) return OP_JZ;
    if (strcmp(mnemonic, "INC") == 0) return OP_INC;
    if (strcmp(mnemonic, "DEC") == 0) return OP_DEC;
    if (strcmp(mnemonic, "MOV") == 0) return OP_MOV;
    if (strcmp(mnemonic, "HALT") == 0) return OP_HALT;
    return -1;
}

// Assemble a single line
void assemble_line(char *line) {
    char *comment = strchr(line, ';');
    if (comment) *comment = '\0';  // Remove comment
    
    trim(line);
    
    if (strlen(line) == 0) return;  // Empty line
    
    // Handle data directive (@address value)
    if (line[0] == '@') {
        int addr, value;
        if (sscanf(line, "@%d %i", &addr, &value) == 2) {
            if (addr < 0 || addr >= MEM_SIZE) {
                error("Address out of range");
            }
            memory[addr] = (uint8_t)value;
            memory_initialized[addr] = 1;  // Mark as initialized
            return;
        } else {
            error("Invalid data directive format");
        }
    }
    
    // Parse instruction
    char mnemonic[16], arg1[16], arg2[16];
    int num_args = sscanf(line, "%s %[^,], %s", mnemonic, arg1, arg2);
    
    if (num_args < 1) return;
    
    // Convert mnemonic to uppercase
    for (int i = 0; mnemonic[i]; i++) {
        mnemonic[i] = toupper(mnemonic[i]);
    }
    
    int opcode = get_opcode(mnemonic);
    if (opcode < 0) {
        error("Unknown instruction");
    }
    
    // Encode based on instruction type
    switch (opcode) {
        case OP_HALT:
        case OP_NOP:
            encode_instruction(opcode, 0, 0, 0);
            break;
            
        case OP_LOAD:
        case OP_STORE:
            if (num_args < 2) error("Missing operands");
            trim(arg1);
            trim(arg2);
            {
                int dest = parse_register(arg1);
                int addr = parse_number(arg2);
                encode_instruction(opcode, dest, 0, addr);
            }
            break;
            
        case OP_ADD:
        case OP_SUB:
        case OP_AND:
        case OP_OR:
        case OP_XOR:
        case OP_MOV:
            if (num_args < 3) error("Missing operands");
            trim(arg1);
            trim(arg2);
            {
                int dest = parse_register(arg1);
                int src = parse_register(arg2);
                encode_instruction(opcode, dest, src, 0);
            }
            break;
            
        case OP_INC:
        case OP_DEC:
            if (num_args < 2) error("Missing operand");
            trim(arg1);
            {
                int dest = parse_register(arg1);
                encode_instruction(opcode, dest, 0, 0);
            }
            break;
            
        case OP_JUMP:
        case OP_JZ:
            if (num_args < 2) error("Missing operand");
            trim(arg1);
            {
                int addr = parse_number(arg1);
                encode_instruction(opcode, 0, 0, addr);
            }
            break;
            
        default:
            error("Unimplemented instruction");
    }
}

// Generate Verilog memory module
void generate_verilog(const char *output_file) {
    FILE *f = fopen(output_file, "w");
    if (!f) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_file);
        exit(1);
    }
    
    fprintf(f, "`timescale 1ns/1ps\n\n");
    fprintf(f, "module memory (\n");
    fprintf(f, "    input clk,\n");
    fprintf(f, "    input [7:0] address,\n");
    fprintf(f, "    input [7:0] write_data,\n");
    fprintf(f, "    input write_enable,\n");
    fprintf(f, "    output reg [7:0] read_data\n");
    fprintf(f, ");\n\n");
    fprintf(f, "    reg [7:0] mem [0:255];\n\n");
    fprintf(f, "    initial begin\n");
    fprintf(f, "        integer i;\n");
    fprintf(f, "        for (i = 0; i < 256; i = i + 1) begin\n");
    fprintf(f, "            mem[i] = 8'h00;\n");
    fprintf(f, "        end\n\n");
    
    // Write initialized memory locations (including zeros!)
    for (int addr = 0; addr < MEM_SIZE; addr++) {
        if (memory_initialized[addr]) {
            fprintf(f, "        mem[%d] = 8'h%02X;\n", addr, memory[addr]);
        }
    }
    
    fprintf(f, "    end\n\n");
    fprintf(f, "    always @(*) begin\n");
    fprintf(f, "        read_data = mem[address];\n");
    fprintf(f, "    end\n\n");
    fprintf(f, "    always @(posedge clk) begin\n");
    fprintf(f, "        if (write_enable)\n");
    fprintf(f, "            mem[address] <= write_data;\n");
    fprintf(f, "    end\n\n");
    fprintf(f, "endmodule\n");
    
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.asm> <output.v>\n", argv[0]);
        fprintf(stderr, "Example: %s program.asm src/memory.v\n", argv[0]);
        return 1;
    }
    
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    
    // Initialize memory to zero
    memset(memory, 0, MEM_SIZE);
    memset(memory_initialized, 0, MEM_SIZE);  //Initialize tracking array
    
    // Open input file
    FILE *f = fopen(input_file, "r");
    if (!f) {
        fprintf(stderr, "Error: Cannot open input file %s\n", input_file);
        return 1;
    }
    
    printf("Assembling %s...\n", input_file);
    
    // Assemble line by line
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), f)) {
        line_number++;
        assemble_line(line);
    }
    
    fclose(f);
    
    // Generate Verilog output
    printf("Generating Verilog output: %s\n", output_file);
    generate_verilog(output_file);
    
    printf("Assembly complete!\n");
    printf("Program size: %d bytes\n", pc);
    
    return 0;
}