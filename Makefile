# Makefile for Custom CPU Project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2
VERILATOR = verilator
VFLAGS = --binary --timing -Wall

# Assembler
ASSEMBLER = tools/assembler
ASM_SRC = programs/test.asm
ASM_CC = gcc
ASM_CFLAGS = -Wall -O2 -o

# Directories
SRC_DIR = src
TB_DIR = testbench
OBJ_DIR = obj_dir
TOOL_DIR = tools
PROG_DIR = programs

# Source files
CPU_SOURCES = $(SRC_DIR)/cpu_top.v \
	          $(SRC_DIR)/memory.v \
	          $(SRC_DIR)/alu.v \
	          $(SRC_DIR)/register_file.v \
	          $(SRC_DIR)/control_unit.v

TB_SOURCE = $(TB_DIR)/cpu_tb.v

# Targets
.PHONY: all assemble compile run clean help assembler run-asm

# Default target
all: compile

# Help target
help:
	@echo "Available targets:"
	@echo "  make assembler    - Build the assembler tool"
	@echo "  make assemble     - Assemble the program (specify ASM_SRC=...)"
	@echo "  make compile      - Compile the CPU design"
	@echo "  make run          - Run the simulation"
	@echo "  make run-asm      - Assemble, compile, and run in one step"
	@echo "  make clean        - Clean build files"
	@echo ""
	@echo "Example:"
	@echo "  make run-asm ASM_SRC=programs/fibonacci.asm"

# Build the assembler
assembler: $(ASSEMBLER)

$(ASSEMBLER): $(TOOL_DIR)/assembler.c
	@echo "Building assembler..."
	$(ASM_CC) $(ASM_CFLAGS) $(ASSEMBLER) $(TOOL_DIR)/assembler.c
	@echo "Assembler built successfully!"

# Assemble program to Verilog memory
assemble: $(ASSEMBLER)
	@echo "Assembling $(ASM_SRC)..."
	@$(ASSEMBLER) $(ASM_SRC) $(SRC_DIR)/memory.v
	@echo "Assembly complete!"

# Compile CPU design
compile: $(CPU_SOURCES) $(TB_SOURCE)
	@echo "Compiling CPU design..."
	$(VERILATOR) $(VFLAGS) --top-module cpu_tb $(TB_SOURCE) $(CPU_SOURCES) 
	@echo "Compilation complete!"

# Run simulation
run:
	@echo "Running simulation..."
	@$(OBJ_DIR)/Vcpu_tb
	@echo ""

# Complete workflow: assemble, compile, and run
run-asm: assembler assemble compile run

# Clean build artifacts
clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR)
	rm -f *.vcd *.log
	rm -f $(ASSEMBLER)
	@echo "Clean complete!"

# Clean everything including generated memory
distclean: clean
	rm -f $(SRC_DIR)/memory.v
	@echo "Deep clean complete!"
