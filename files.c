#include <stdio.h>
#include <stdlib.h>
#include "fileobject.h"

int getFileSize(FileObject *o)
{
    if (!o->fptr)
	return -1;
    fseek(o->fptr, 0, SEEK_END);
    o->fileSize = ftell(o->fptr);
    rewind(o->fptr);
    return 0;
}

int getRowCount(FileObject *o)
{
    int c;
    int buff = 0;
    int row = 0;
    
    while ((c = fgetc(o->fptr)) != EOF)
    {
	if (c == '\n')
	    row++;

	buff = c;
    }
    if (buff != '\n')
	row += 1;

    o->rowCount = row;
    return 0;
}
