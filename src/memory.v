`timescale 1ns/1ps

module memory (
    input clk,
    input [7:0] address,
    input [7:0] write_data,
    input write_enable,
    output reg [7:0] read_data
);

    reg [7:0] mem [0:255];

    initial begin
        integer i;
        for (i = 0; i < 256; i = i + 1) begin
            mem[i] = 8'h00;
        end

        mem[0] = 8'h10;
        mem[1] = 8'hC8;
        mem[2] = 8'h14;
        mem[3] = 8'hC9;
        mem[4] = 8'h38;
        mem[5] = 8'h00;
        mem[6] = 8'h39;
        mem[7] = 8'h00;
        mem[8] = 8'h28;
        mem[9] = 8'h64;
        mem[10] = 8'hA0;
        mem[11] = 8'h00;
        mem[12] = 8'h4D;
        mem[13] = 8'h00;
        mem[14] = 8'hD0;
        mem[15] = 8'h00;
        mem[100] = 8'h00;
        mem[200] = 8'h05;
        mem[201] = 8'h0A;
    end

    always @(*) begin
        read_data = mem[address];
    end

    always @(posedge clk) begin
        if (write_enable)
            mem[address] <= write_data;
    end

endmodule
