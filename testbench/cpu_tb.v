`timescale 1ns/1ps

module cpu_tb;
    reg clk;
    reg reset;
    wire halt_flag;

    // time since reset deassertion and cycle counter
    time t0;
    integer cycle;
    reg reset_q; // for synchronous edge detect

    // nice ns formatting
    initial begin
        t0 = 0;
        cycle = 0;
        reset_q = 1'b1;
        $timeformat(-9, 0, " ns", 10);
    end

    // DUT
    cpu_top cpu_inst (
        .clk(clk),
        .reset(reset),
        .halt_flag(halt_flag)
    );

    // 100 MHz clock
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // single driver for cycle (synchronous reset only)
    always @(posedge clk) begin
        if (reset) begin
            cycle <= 0;
        end else begin
            cycle <= cycle + 1;
        end
    end

    // capture time-zero on reset deassertion synchronously (no async usage)
    always @(posedge clk) begin
        reset_q <= reset;
        if (reset_q && !reset) begin
            t0 <= $time;
        end
    end

    // trace useful pipeline states
    always @(posedge clk) begin
        if (!reset && cpu_inst.state == 3'b010) begin // DECODE
            $display("Time=%0t (cycle %0d) PC=%02h IR=%04h State=%02h",
                     ($time - t0), cycle, cpu_inst.pc, cpu_inst.ir, cpu_inst.state);
        end
        if (!reset && cpu_inst.state == 3'b011) begin // EXECUTE
            $display("EXECUTE @ %0t (cycle %0d): opcode=%04b, dest=%0d, src=%0d, imm=%02h",
                     ($time - t0), cycle, cpu_inst.opcode, cpu_inst.dest_reg, cpu_inst.src_reg, cpu_inst.immediate);
            $display("  reg_write=%0d, mem_write=%0d, alu_enable=%0d",
                     cpu_inst.reg_write, cpu_inst.mem_write, cpu_inst.alu_enable);
            $display("  reg_data1=%3d, reg_data2=%3d, alu_result=%3d",
                     cpu_inst.reg_data1, cpu_inst.reg_data2, cpu_inst.alu_result);
            $display("  mem_address=%02h, mem_read_data=%3d",
                     cpu_inst.mem_address, cpu_inst.mem_read_data);
            $display("  zero_flag=%0d, pc_jump=%0d",
                     cpu_inst.zero_flag, cpu_inst.pc_jump);
            if (cpu_inst.opcode == 4'b1001) begin
                if (cpu_inst.pc_jump)
                    $display("  JZ: Taking jump to %3d", cpu_inst.immediate);
                else
                    $display("  JZ: Not taking jump");
            end
        end
    end

    // reset, wait for HALT, dump final state
    initial begin
        reset = 1;
        #10000;         // hold reset 10 us
        reset = 0;

        wait (halt_flag == 1);
        #50000;         // settle

        $display("\n=== Final CPU State ===");
        $display("R0 = %3d", cpu_inst.reg_file_inst.registers[0]);
        $display("R1 = %3d", cpu_inst.reg_file_inst.registers[1]);
        $display("R2 = %3d", cpu_inst.reg_file_inst.registers[2]);
        $display("R3 = %3d", cpu_inst.reg_file_inst.registers[3]);
        $display("mem[100] = %3d", cpu_inst.mem_inst.mem[100]);
        $display("mem[101] = %3d", cpu_inst.mem_inst.mem[101]);
        $display("mem[200] = %3d", cpu_inst.mem_inst.mem[200]);
        $display("mem[201] = %3d", cpu_inst.mem_inst.mem[201]);
        $display("mem[202] = %3d", cpu_inst.mem_inst.mem[202]);
        $display("PC = 0x%02h, State = %0d, Halt = %0d",
                 cpu_inst.pc, cpu_inst.state, halt_flag);
        $display("\n=== Test Complete ===");
        $finish;
    end

    // safety timeout
    initial begin
        #10000000;  // 10 ms
        $display("\n*** TIMEOUT ***");
        $finish;
    end

    // VCD dump (compile Verilator with --trace to enable)
    initial begin
        $dumpfile("cpu.vcd");
        $dumpvars(0, cpu_tb);
        // $dumpvars(0, cpu_tb.cpu_inst.mem_inst.mem[200]);
        // $dumpvars(0, cpu_tb.cpu_inst.mem_inst.mem[201]);
    end
endmodule
