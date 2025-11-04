// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_tb.h for the primary calling header

#include "verilated.h"

#include "Vcpu_tb__Syms.h"
#include "Vcpu_tb___024root.h"

void Vcpu_tb___024root___ctor_var_reset(Vcpu_tb___024root* vlSelf);

Vcpu_tb___024root::Vcpu_tb___024root(Vcpu_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcpu_tb___024root___ctor_var_reset(this);
}

void Vcpu_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcpu_tb___024root::~Vcpu_tb___024root() {
}
