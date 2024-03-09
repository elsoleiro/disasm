#ifndef INSTRUCTIONS_STRUCT
#define INSTRUCTIONS_STRUCT

typedef struct {
    unsigned char opcode;
    unsigned char d;
    unsigned char w;
    unsigned char mod;
    unsigned char reg;
    unsigned char rm;
} Instruction;

#endif
