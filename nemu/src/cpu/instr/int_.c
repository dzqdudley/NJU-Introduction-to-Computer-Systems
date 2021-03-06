#include "cpu/intr.h"
#include "cpu/instr.h"

/*
Put the implementations of `int' instructions here.

Special note for `int': please use the instruction name `int_' instead of `int'.
*/
make_instr_func(int_) {
    OPERAND imm;
    imm.type = OPR_IMM;
    imm.data_size = 8;
    imm.addr = eip+1;
    imm.sreg = SREG_CS;
    operand_read(&imm);
#ifdef IA32_INTR
    if (cpu.cr0.pe) {
        raise_sw_intr(imm.val);
    } else {
        assert(0);
    }
#endif
    return 0;
}