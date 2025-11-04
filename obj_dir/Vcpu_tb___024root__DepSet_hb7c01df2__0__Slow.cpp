// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_tb.h for the primary calling header

#include "verilated.h"

#include "Vcpu_tb__Syms.h"
#include "Vcpu_tb___024root.h"

VL_ATTR_COLD void Vcpu_tb___024root___eval_initial__TOP(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i;
    cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelf->cpu_tb__DOT__t0 = 0ULL;
    vlSelf->cpu_tb__DOT__cycle = 0U;
    vlSelf->cpu_tb__DOT__reset_q = 1U;
    VL_TIMEFORMAT_IINI(0xfffffff7U, 0U, std::string{" ns"}, 0xaU, vlSymsp->_vm_contextp__);
    vlSymsp->_vm_contextp__->dumpfile(std::string{"cpu.vcd"});
    VL_PRINTF_MT("-Info: testbench/cpu_tb.v:112: $dumpvar ignored, as Verilated without --trace\n");
    cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i)) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[(0xffU 
                                                                & cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i)] = 0U;
        cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__unnamedblk1__DOT__i);
    }
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0U] = 0x10U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[1U] = 0xc8U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[2U] = 0x14U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[3U] = 0xc9U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[4U] = 0x38U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[5U] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[6U] = 0x39U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[7U] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[8U] = 0x28U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[9U] = 0x64U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xaU] = 0xa0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xbU] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xcU] = 0x4dU;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xdU] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xeU] = 0xd0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xfU] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0x64U] = 0U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xc8U] = 5U;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[0xc9U] = 0xaU;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__stl(Vcpu_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcpu_tb___024root___eval_triggers__stl(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcpu_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
