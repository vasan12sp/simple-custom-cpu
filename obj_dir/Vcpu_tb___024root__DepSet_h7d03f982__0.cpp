// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_tb.h for the primary calling header

#include "verilated.h"

#include "Vcpu_tb___024root.h"

VL_ATTR_COLD void Vcpu_tb___024root___eval_initial__TOP(Vcpu_tb___024root* vlSelf);
VlCoroutine Vcpu_tb___024root___eval_initial__TOP__0(Vcpu_tb___024root* vlSelf);
VlCoroutine Vcpu_tb___024root___eval_initial__TOP__1(Vcpu_tb___024root* vlSelf);
VlCoroutine Vcpu_tb___024root___eval_initial__TOP__2(Vcpu_tb___024root* vlSelf);

void Vcpu_tb___024root___eval_initial(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_initial\n"); );
    // Body
    Vcpu_tb___024root___eval_initial__TOP(vlSelf);
    Vcpu_tb___024root___eval_initial__TOP__0(vlSelf);
    Vcpu_tb___024root___eval_initial__TOP__1(vlSelf);
    Vcpu_tb___024root___eval_initial__TOP__2(vlSelf);
    vlSelf->__Vtrigrprev__TOP__cpu_tb__DOT__clk = vlSelf->cpu_tb__DOT__clk;
    vlSelf->__Vtrigrprev__TOP__cpu_tb__DOT__cpu_inst__DOT__state 
        = vlSelf->cpu_tb__DOT__cpu_inst__DOT__state;
}

VL_INLINE_OPT VlCoroutine Vcpu_tb___024root___eval_initial__TOP__0(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_initial__TOP__0\n"); );
    // Body
    vlSelf->cpu_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388U, 
                                           "testbench/cpu_tb.v", 
                                           31);
        vlSelf->cpu_tb__DOT__clk = (1U & (~ (IData)(vlSelf->cpu_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vcpu_tb___024root___eval_initial__TOP__1(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_initial__TOP__1\n"); );
    // Body
    vlSelf->cpu_tb__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0x989680U, "testbench/cpu_tb.v", 
                                       80);
    vlSelf->cpu_tb__DOT__reset = 0U;
    while ((4U != (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))) {
        co_await vlSelf->__VtrigSched_h20714f6e__0.trigger(
                                                           "@([changed] cpu_tb.cpu_inst.state)", 
                                                           "testbench/cpu_tb.v", 
                                                           83);
    }
    co_await vlSelf->__VdlySched.delay(0x2faf080U, 
                                       "testbench/cpu_tb.v", 
                                       84);
    VL_WRITEF("\n=== Final CPU State ===\nR0 = %3#\nR1 = %3#\nR2 = %3#\nR3 = %3#\nmem[100] = %3#\nmem[101] = %3#\nmem[200] = %3#\nmem[201] = %3#\nmem[202] = %3#\nPC = 0x%02x, State = %0#, Halt = %0#\n\n=== Test Complete ===\n",
              8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
              [0U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
              [1U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
              [2U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers
              [3U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
              [0x64U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
              [0x65U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
              [0xc8U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
              [0xc9U],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem
              [0xcaU],8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc,
              3,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state),
              1,(4U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state)));
    VL_FINISH_MT("testbench/cpu_tb.v", 99, "");
}

VL_INLINE_OPT VlCoroutine Vcpu_tb___024root___eval_initial__TOP__2(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_initial__TOP__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x540be400U, 
                                       "testbench/cpu_tb.v", 
                                       104);
    VL_WRITEF("\n*** TIMEOUT ***\n");
    VL_FINISH_MT("testbench/cpu_tb.v", 106, "");
}

void Vcpu_tb___024root___eval_act(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_ha6a68ece_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_h586042f1_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_hd759244c_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcpu_tb__ConstPool__TABLE_h1d4d8edc_0;

VL_INLINE_OPT void Vcpu_tb___024root___nba_sequent__TOP__0(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc;
    __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc = 0;
    CData/*2:0*/ __Vdly__cpu_tb__DOT__cpu_inst__DOT__state;
    __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 0;
    CData/*0:0*/ __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v0;
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v0 = 0;
    CData/*1:0*/ __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4;
    __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 = 0;
    CData/*7:0*/ __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4;
    __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 = 0;
    CData/*0:0*/ __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4;
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 = 0;
    CData/*7:0*/ __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0;
    __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0;
    __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0;
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 = 0U;
    __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc = vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc;
    __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = vlSelf->cpu_tb__DOT__cpu_inst__DOT__state;
    if (VL_UNLIKELY(((~ (IData)(vlSelf->cpu_tb__DOT__reset)) 
                     & (2U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))))) {
        VL_WRITEF("Time=%0t (cycle %0d) PC=%02x IR=%04x State=%02x\n",
                  64,((QData)(VL_TIME_UNITED_Q(1000)) 
                      - vlSelf->cpu_tb__DOT__t0),-9,
                  32,vlSelf->cpu_tb__DOT__cycle,8,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc),
                  16,vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir,
                  3,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state));
    }
    if (VL_UNLIKELY(((~ (IData)(vlSelf->cpu_tb__DOT__reset)) 
                     & (3U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))))) {
        VL_WRITEF("EXECUTE @ %0t (cycle %0d): opcode=%04b, dest=%0#, src=%0#, imm=%02x\n  reg_write=%0#, mem_write=%0#, alu_enable=%0#\n  reg_data1=%3#, reg_data2=%3#, alu_result=%3#\n  mem_address=%02x, mem_read_data=%3#\n  zero_flag=%0#, pc_jump=%0#\n",
                  64,((QData)(VL_TIME_UNITED_Q(1000)) 
                      - vlSelf->cpu_tb__DOT__t0),-9,
                  32,vlSelf->cpu_tb__DOT__cycle,4,(0xfU 
                                                   & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                                      >> 0xcU)),
                  2,(3U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                           >> 0xaU)),2,(3U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                                              >> 8U)),
                  8,(0xffU & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir)),
                  1,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write),
                  1,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_write,
                  1,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_enable),
                  8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1,
                  8,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data2),
                  8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__alu_result,
                  8,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_address),
                  8,vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data,
                  1,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__zero_flag),
                  1,vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc_jump);
        if ((9U == (0xfU & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                            >> 0xcU)))) {
            if (vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc_jump) {
                VL_WRITEF("  JZ: Taking jump to %3#\n",
                          8,(0xffU & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir)));
            } else {
                VL_WRITEF("  JZ: Not taking jump\n");
            }
        }
    }
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v0 = 0U;
    __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 = 0U;
    if (((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_write) 
         & (3U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state)))) {
        __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 
            = vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_data1;
        __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 = 1U;
        __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0 
            = vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_address;
    }
    vlSelf->cpu_tb__DOT__cycle = ((IData)(vlSelf->cpu_tb__DOT__reset)
                                   ? 0U : ((IData)(1U) 
                                           + vlSelf->cpu_tb__DOT__cycle));
    if (vlSelf->cpu_tb__DOT__reset) {
        __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v0 = 1U;
    } else if (VL_UNLIKELY(((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write) 
                            & (3U == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))))) {
        VL_WRITEF("  [REGFILE] Writing R%0# = %3#\n",
                  2,(3U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                           >> 0xaU)),8,(IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write_data));
        __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 
            = vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_write_data;
        __Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 = 1U;
        __Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4 
            = (3U & ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir) 
                     >> 0xaU));
    }
    if (vlSelf->cpu_tb__DOT__reset) {
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc = 0U;
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 0U;
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir = 0U;
    } else if ((4U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))) {
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 
            ((2U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))
              ? 0U : ((1U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))
                       ? 0U : 4U));
    } else if ((2U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))) {
        if ((1U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))) {
            if ((0xdU == (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__opcode))) {
                __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 4U;
            } else if (vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc_jump) {
                __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc 
                    = vlSelf->cpu_tb__DOT__cpu_inst__DOT__immediate;
                __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 0U;
            } else {
                __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 0U;
            }
        } else {
            __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 3U;
        }
    } else if ((1U & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__state))) {
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc)));
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir = ((0xff00U 
                                                   & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir)) 
                                                  | (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data));
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 2U;
    } else {
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc)));
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir = ((0xffU 
                                                   & (IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__ir)) 
                                                  | ((IData)(vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_read_data) 
                                                     << 8U));
        __Vdly__cpu_tb__DOT__cpu_inst__DOT__state = 1U;
    }
    if (__Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem[__Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0] 
            = __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__mem_inst__DOT__mem__v0;
    }
    if (((IData)(vlSelf->cpu_tb__DOT__reset_q) & (~ (IData)(vlSelf->cpu_tb__DOT__reset)))) {
        vlSelf->cpu_tb__DOT__t0 = VL_TIME_UNITED_Q(1000);
    }
    if (__Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v0) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[0U] = 0U;
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[1U] = 0U;
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[2U] = 0U;
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[3U] = 0U;
    }
    if (__Vdlyvset__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4) {
        vlSelf->cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers[__Vdlyvdim0__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4] 
            = __Vdlyvval__cpu_tb__DOT__cpu_inst__DOT__reg_file_inst__DOT__registers__v4;
    }
    vlSelf->cpu_tb__DOT__reset_q = vlSelf->cpu_tb__DOT__reset;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__pc = __Vdly__cpu_tb__DOT__cpu_inst__DOT__pc;
    vlSelf->cpu_tb__DOT__cpu_inst__DOT__state = __Vdly__cpu_tb__DOT__cpu_inst__DOT__state;
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

void Vcpu_tb___024root___eval_nba(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vcpu_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vcpu_tb___024root___eval_triggers__act(Vcpu_tb___024root* vlSelf);
void Vcpu_tb___024root___timing_commit(Vcpu_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__act(Vcpu_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vcpu_tb___024root___timing_resume(Vcpu_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu_tb___024root___dump_triggers__nba(Vcpu_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vcpu_tb___024root___eval(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vcpu_tb___024root___eval_triggers__act(vlSelf);
            Vcpu_tb___024root___timing_commit(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vcpu_tb___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("testbench/cpu_tb.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vcpu_tb___024root___timing_resume(vlSelf);
                Vcpu_tb___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vcpu_tb___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("testbench/cpu_tb.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vcpu_tb___024root___eval_nba(vlSelf);
        }
    }
}

void Vcpu_tb___024root___timing_commit(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___timing_commit\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.at(2U))))) {
        vlSelf->__VtrigSched_h20714f6e__0.commit("@([changed] cpu_tb.cpu_inst.state)");
    }
}

void Vcpu_tb___024root___timing_resume(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___timing_resume\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(1U)) {
        vlSelf->__VdlySched.resume();
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        vlSelf->__VtrigSched_h20714f6e__0.resume("@([changed] cpu_tb.cpu_inst.state)");
    }
}

#ifdef VL_DEBUG
void Vcpu_tb___024root___eval_debug_assertions(Vcpu_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
