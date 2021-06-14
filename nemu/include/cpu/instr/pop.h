#ifndef __INSTR_POP_H__
#define __INSTR_POP_H__
/*
Put the declarations of `pop' instructions here.
*/
uint32_t pop_(int datasize);

make_instr_func(pop_rm_v);
make_instr_func(pop_r_v);

make_instr_func(popa);

#endif
