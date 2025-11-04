module alu (
    input [3:0] opcode,
    input [7:0] operand_a,
    input [7:0] operand_b,
    output reg [7:0] result,
    output reg zero
);
    always @(*) begin
        case (opcode)
            4'b0011: result = operand_a + operand_b;  // ADD
            4'b0100: result = operand_a - operand_b;  // SUB
            4'b0101: result = operand_a & operand_b;  // AND
            4'b0110: result = operand_a | operand_b;  // OR
            4'b1010: result = operand_a + 1;          // INC
            4'b1011: result = operand_a - 1;          // DEC
            4'b1001: result = operand_a;              // JZ
            default: result = 8'h00;
        endcase
        zero = (result == 8'h00);
    end
endmodule
