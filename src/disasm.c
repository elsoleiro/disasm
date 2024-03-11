/*
             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
	                   January 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files/files.h"
#include "instructions/instructions.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
	fprintf(stderr, "%s", "incorrect number of arguments");
	return -1;
    }
    
    FileObject o;
    o.fileName = argv[1];
    o.fptr = fopen(o.fileName, "rb");

    if (getContents(&o) != 0)
	return -1;

    Instruction inst = getInstruction(&o);
    free(o.fileData);

    char *asmb = (char *) calloc(4, sizeof(char));
    switch(inst.opcode)
    {
	case 34:
	    strcpy(asmb, "mov");
    }

    char regs[2][8][3] = {
	{"AL", "CL", "DL", "BL", "AH", "CH", "DH", "BH"},
	{"AX", "CX", "DX", "BX", "SP", "BP", "SI", "DI"}
    };
}
