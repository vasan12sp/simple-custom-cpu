module control_unit (
    input [3:0] opcode,
    input [2:0] state,
    input zero_flag,
    output reg reg_write,
    output reg mem_write,
    output reg alu_enable,
    output reg pc_jump
);
    localparam EXECUTE = 3'b011;

    always @(*) begin
        reg_write = 0;
        mem_write = 0;
        alu_enable = 0;
        pc_jump = 0;
        
        if (state == EXECUTE) begin
            case (opcode)
                4'b0001: reg_write = 1;                    // LOAD
                4'b0010: mem_write = 1;                    // STORE
                4'b0011: begin reg_write = 1; alu_enable = 1; end  // ADD
                4'b0100: begin reg_write = 1; alu_enable = 1; end  // SUB
                4'b0101: begin reg_write = 1; alu_enable = 1; end  // AND
                4'b0110: begin reg_write = 1; alu_enable = 1; end  // OR
                4'b0111: reg_write = 1;                    // MOV
                4'b1000: pc_jump = 1;                      // JUMP
                4'b1001: begin alu_enable = 1; pc_jump = zero_flag; end  // JZ
                4'b1010: begin reg_write = 1; alu_enable = 1; end  // INC
                4'b1011: begin reg_write = 1; alu_enable = 1; end  // DEC
                default: begin end
            endcase
        end
    end
endmodule
