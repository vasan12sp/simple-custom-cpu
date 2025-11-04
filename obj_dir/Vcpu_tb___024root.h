// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu_tb.h for the primary calling header

#ifndef VERILATED_VCPU_TB___024ROOT_H_
#define VERILATED_VCPU_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"

class Vcpu_tb__Syms;

class Vcpu_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ cpu_tb__DOT__clk;
    CData/*0:0*/ cpu_tb__DOT__reset;
    CData/*0:0*/ cpu_tb__DOT__reset_q;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__pc;
    CData/*2:0*/ cpu_tb__DOT__cpu_inst__DOT__state;
    CData/*3:0*/ cpu_tb__DOT__cpu_inst__DOT__opcode;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__immediate;
    CData/*0:0*/ cpu_tb__DOT__cpu_inst__DOT__reg_write;
    CData/*0:0*/ cpu_tb__DOT__cpu_inst__DOT__mem_write;
    CData/*0:0*/ cpu_tb__DOT__cpu_inst__DOT__alu_enable;
    CData/*0:0*/ cpu_tb__DOT__cpu_inst__DOT__pc_jump;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__reg_data1;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__reg_data2;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__alu_result;
    CData/*0:0*/ cpu_tb__DOT__cpu_inst__DOT__zero_flag;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__mem_read_data;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__mem_address;
    CData/*7:0*/ cpu_tb__DOT__cpu_inst__DOT__reg_write_data;
    CData/*0:0*/ __Vtrigrprev__TOP__cpu_tb__DOT__clk;
    CData/*2:0*/ __Vtrigrprev__TOP__cpu_tb__DOT__cpu_inst__DOT__state;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ cpu_tb__DOT__cpu_inst__DOT__ir;
    IData/*31:0*/ cpu_tb__DOT__cycle;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ cpu_tb__DOT__t0;
    VlUnpacked<CData/*7:0*/, 4> cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers;
    VlUnpacked<CData/*7:0*/, 256> cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h20714f6e__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcpu_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu_tb___024root(Vcpu_tb__Syms* symsp, const char* v__name);
    ~Vcpu_tb___024root();
    VL_UNCOPYABLE(Vcpu_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
