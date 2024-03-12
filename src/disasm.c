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

    char regs[2][8][3] = {
	{"AL", "CL", "DL", "BL", "AH", "CH", "DH", "BH"},
	{"AX", "CX", "DX", "BX", "SP", "BP", "SI", "DI"}
    };

    char *op = (char *) calloc(3, sizeof(char));
    char *src = (char *) calloc(2, sizeof(char));
    char *dst = (char *) calloc(2, sizeof(char));
    
    switch(inst.opcode) // OBTAINING OPCODE
    {
	case 34:
	    strcpy(op, "mov");
    }
    
    /*
      this should actually depend on MOD = 11,
      add it
    */
    switch(inst.d) // D GIVES DIRECTION THROUGH REG
    {
	case 0: // REG is src
	{
	    switch(inst.w)
	    {
		case 0: // BYTE
		{
		    strcpy(src, regs[0][inst.reg]);
		    strcpy(dst, regs[0][inst.rm]);
		    break;
		}

		case 1: // WORD
		{
    		    strcpy(src, regs[1][inst.reg]);
    		    strcpy(dst, regs[1][inst.rm]);
		    break;
		}
	    }
	    break;
	}
	
	case 1: // REG is dst
	{
	    switch(inst.w)
	    {
		case 0:
		{
		    strcpy(src, regs[0][inst.rm]);
		    strcpy(dst, regs[0][inst.reg]);
		    break;
		}

		case 1:
		{
    		    strcpy(src, regs[1][inst.rm]);
    		    strcpy(dst, regs[1][inst.reg]);
		    break;
		}
	    }
	    break;
	}
    }

    free(op);
    free(src);
    free(dst);
}
