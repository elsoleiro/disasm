#include <stdio.h>
#include <stdlib.h>
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

    free(o.fileData);
    return 0;
}    
