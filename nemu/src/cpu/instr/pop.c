#include "cpu/instr.h"
/*
Put the implementations of `pop' instructions here.
*/
static void instr_execute_1op(){
    opr_dest.data_size = data_size;
    opr_dest.type = OPR_MEM;
    opr_dest.addr = cpu.esp;
    operand_read(&opr_dest);
    
    cpu.esp += (data_size / 8);
    opr_src.val = opr_dest.val;
    operand_write(&opr_src);
}

make_instr_impl_1op(pop, r, v)