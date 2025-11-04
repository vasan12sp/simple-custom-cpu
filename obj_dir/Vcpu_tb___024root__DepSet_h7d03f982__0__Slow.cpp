// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_tb.h for the primary calling header

#include "verilated.h"

#include "Vcpu_tb___024root.h"

VL_ATTR_COLD void Vcpu_tb___024root___eval_static(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vcpu_tb___024root___eval_final(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vcpu_tb___024root___eval_triggers__stl(Vcpu_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__stl(Vcpu_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___eval_stl(Vcpu_tb___024root* vlSelf);

VL_ATTR_COLD void Vcpu_tb___024root___eval_settle(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vcpu_tb___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vcpu_tb___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("testbench/cpu_tb.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vcpu_tb___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__stl(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_ha6a68ece_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_h586042f1_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_hd759244c_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_h1d4d8edc_0;

VL_ATTR_COLD void Vcpu_tb___024root___stl_sequent__TOP__0(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__opcode = (0xfU 
                                                  & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                                     >> 0xcU));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__immediate = 
        (0xffU & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_address 
        = (0xffU & (((0U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state)) 
                     | (1U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state)))
                     ? (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc)
                     : (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir)));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1 = 
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
        [(3U & ((7U == (0xfU & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                >> 0xcU))) ? ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                              >> 8U)
                 : ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                    >> 0xaU)))];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2 = 
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
        [(3U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                >> 8U))];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data 
        = vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
        [vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_address];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_result 
        = (0xffU & ((0x8000U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                     ? ((0x4000U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                         ? 0U : ((0x2000U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                  ? ((0x1000U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                      ? ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1) 
                                         - (IData)(1U))
                                      : ((IData)(1U) 
                                         + (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1)))
                                  : ((0x1000U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                      ? (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1)
                                      : 0U))) : ((0x4000U 
                                                  & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                  ? 
                                                 ((0x2000U 
                                                   & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                   ? 
                                                  ((0x1000U 
                                                    & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1) 
                                                    | (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2)))
                                                   : 
                                                  ((0x1000U 
                                                    & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                    ? 
                                                   ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1) 
                                                    & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2))
                                                    : 
                                                   ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1) 
                                                    - (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2))))
                                                  : 
                                                 ((0x2000U 
                                                   & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                   ? 
                                                  ((0x1000U 
                                                    & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir))
                                                    ? 
                                                   ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1) 
                                                    + (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2))
                                                    : 0U)
                                                   : 0U))));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__zero_flag = 
        (0U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_result));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write_data 
        = ((1U == (0xfU & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                           >> 0xcU))) ? (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data)
            : ((7U == (0xfU & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                               >> 0xcU))) ? (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2)
                : (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_result)));
    __Vtableidx1 = (((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__zero_flag) 
                     << 7U) | ((0x78U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                         >> 9U)) | (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state)));
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write = 
        Vcpu_tb__ConstPool__TABLE_ha6a68ece_0[__Vtableidx1];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_write = 
        Vcpu_tb__ConstPool__TABLE_h586042f1_0[__Vtableidx1];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_enable 
        = Vcpu_tb__ConstPool__TABLE_hd759244c_0[__Vtableidx1];
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc_jump = Vcpu_tb__ConstPool__TABLE_h1d4d8edc_0
        [__Vtableidx1];
}

VL_ATTR_COLD void Vcpu_tb___024root___eval_stl(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vcpu_tb___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__act(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge cpu_tb.clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] cpu_tb.cpu_inst.state)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__nba(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge cpu_tb.clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] cpu_tb.cpu_inst.state)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcpu_tb___024root___ctor_var_reset(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->cpu_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__t0 = VL_RAND_RESET_Q(64);
    vlSelf->cpu_tb__DOT__cycle = VL_RAND_RESET_I(32);
    vlSelf->cpu_tb__DOT__reset_q = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir = VL_RAND_RESET_I(16);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__opcode = VL_RAND_RESET_I(4);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__immediate = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_write = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_enable = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc_jump = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1 = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2 = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_result = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__zero_flag = VL_RAND_RESET_I(1);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_address = VL_RAND_RESET_I(8);
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write_data = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vtrigrprev__TOP__cpu_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__cpu_tb__DOT__cpu_inst__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->__VactDidInit = 0;
}
