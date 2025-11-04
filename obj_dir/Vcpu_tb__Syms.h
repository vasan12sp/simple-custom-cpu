// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCPU_TB__SYMS_H_
#define VERILATED_VCPU_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcpu_tb.h"

// INCLUDE MODULE CLASSES
#include "Vcpu_tb___024root.h"

// SYMS CLASS (contains all model state)
class Vcpu_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcpu_tb* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcpu_tb___024root              TOP;

    // CONSTRUCTORS
    Vcpu_tb__Syms(VerilatedContext* contextp, const char* namep, Vcpu_tb* modelp);
    ~Vcpu_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
