#include <stdio.h>
#include <stdlib.h>
#include "fileobject.h"

int getFileSize(FileObject *o)
{
    fseek(o->fptr, 0, SEEK_END);
    o->fileSize = ftell(o->fptr);
    rewind(o->fptr);
    return 0;
}

int getRowCount(FileObject *o)
{
    int c;
    int buff = 0;
    int rows = 0;
    
    while ((c = fgetc(o->fptr)) != EOF)
    {
	if (c == '\n')
	    rows++;

	buff = c;
    }
    if (buff != '\n')
	rows += 1;

    o->rowCount = rows;
    return 0;
}