#include "cpu/instr.h"
#include "device/port_io.h"
#define AL cpu.gpr[0]._8[0]
#define AX cpu.gpr[0]._16
#define DX cpu.gpr[2]._16
/*
Put the implementations of `out' instructions here.
*/
make_instr_func(out_b)
{
    pio_write(DX, 1, AL);
    return 1;
}

make_instr_func(out_v)
{
    if (data_size == 16)
        pio_write(DX, 2, AX);
    else
        pio_write(DX, 4, cpu.eax);
    return 1;
}
