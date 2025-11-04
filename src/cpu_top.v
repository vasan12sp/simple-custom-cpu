module cpu_top (
    input clk,
    input reset,
    output halt_flag
);
    localparam FETCH = 3'b000;
    localparam FETCH2 = 3'b001;
    localparam DECODE = 3'b010;
    localparam EXECUTE = 3'b011;
    localparam HALT_STATE = 3'b100;

    reg [7:0] pc;
    reg [15:0] ir;
    reg [2:0] state;

    wire [3:0] opcode = ir[15:12];
    wire [1:0] dest_reg = ir[11:10];
    wire [1:0] src_reg = ir[9:8];
    wire [7:0] immediate = ir[7:0];

    wire reg_write, mem_write, alu_enable, pc_jump;
    wire [7:0] reg_data1, reg_data2, alu_result;
    wire zero_flag;
    wire [7:0] mem_read_data, mem_address;
    
    wire [7:0] reg_write_data = (opcode == 4'b0001) ? mem_read_data :
                                 (opcode == 4'b0111) ? reg_data2 :
                                 alu_result;

    assign mem_address = (state == FETCH || state == FETCH2) ? pc : immediate;
    assign halt_flag = (state == HALT_STATE);

    wire [1:0] read_addr_1 = (opcode == 4'b0111) ? src_reg : dest_reg;
    wire [1:0] read_addr_2 = src_reg;

    register_file reg_file_inst (
        .clk(clk),
        .reset(reset),
        .write_enable(reg_write && (state == EXECUTE)),
        .write_addr(dest_reg),
        .write_data(reg_write_data),
        .read_addr1(read_addr_1),
        .read_addr2(read_addr_2),
        .read_data1(reg_data1),
        .read_data2(reg_data2)
    );

    alu alu_inst (
        .opcode(opcode),
        .operand_a(reg_data1),
        .operand_b(reg_data2),
        .result(alu_result),
        .zero(zero_flag)
    );

    memory mem_inst (
        .clk(clk),
        .address(mem_address),
        .write_enable(mem_write && (state == EXECUTE)),
        .write_data(reg_data1),
        .read_data(mem_read_data)
    );

    control_unit ctrl_inst (
        .opcode(opcode),
        .state(state),
        .zero_flag(zero_flag),
        .reg_write(reg_write),
        .mem_write(mem_write),
        .alu_enable(alu_enable),
        .pc_jump(pc_jump)
    );

    always @(posedge clk) begin
        if (reset) begin
            pc <= 8'h00;
            state <= FETCH;
            ir <= 16'h0000;
        end else begin
            case (state)
                FETCH: begin
                    ir[15:8] <= mem_read_data;
                    pc <= pc + 1;
                    state <= FETCH2;
                end
                FETCH2: begin
                    ir[7:0] <= mem_read_data;
                    pc <= pc + 1;
                    state <= DECODE;
                end
                DECODE: begin
                    state <= EXECUTE;
                end
                EXECUTE: begin
                    if (opcode == 4'b1101) begin
                        state <= HALT_STATE;
                    end else if (pc_jump) begin
                        pc <= immediate;
                        state <= FETCH;
                    end else begin
                        state <= FETCH;
                    end
                end
                HALT_STATE: state <= HALT_STATE;
                default: state <= FETCH;
            endcase
        end
    end
endmodule
