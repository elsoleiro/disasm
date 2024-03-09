#include <stdio.h>
#include "instruction.h"
#include "../files/file.h"

unsigned char getBits(
    unsigned char nbits,
    unsigned char offset,
    unsigned char byte)
{
    return (byte & (((1 << nbits) - 1) << offset)) >> offset;
}

Instruction getInstruction(FileObject *o)
{
    Instruction inst;

    inst.opcode = getBits(6, 2, o->fileData[0]);
    inst.d = getBits(1, 1, o->fileData[0]);
    inst.w = getBits(1, 0, o->fileData[0]);
    inst.mod = getBits(2, 6, o->fileData[1]);
    inst.reg = getBits(3, 3, o->fileData[1]);
    inst.rm = getBits(3, 0, o->fileData[1]);

    return inst;
}
