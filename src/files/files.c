#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int getFileSize(FileObject *o)
{
    fseek(o->fptr, 0, SEEK_END);
    o->fileSize = ftell(o->fptr);
    rewind(o->fptr);
    if (o->fileSize == 0)
	return -1;
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
    
    rewind(o->fptr);
    o->rowCount = rows;
    if (o->rowCount == 0)
	return -1;
    return 0;
}

int getData(FileObject *o)
{
    o->fileData = (unsigned char *) calloc(
	o->fileSize, sizeof(unsigned char));
    if (o->fileData == NULL)
	return -1;
    
    int c;
    int i = 0;
    
    while ((c = fgetc(o->fptr)) != EOF)
    {
	o->fileData[i] = (unsigned char) c;
	i++;
    }
    
    return 0;
}

int getContents(FileObject *o)
{
    
    if (o->fptr == NULL)
    {
	fprintf(stderr, "%s", "possible incorrect filename");
	return -1;
    }

    if (getFileSize(o) != 0)
    {
	fprintf(stderr, "%s", "file size 0");
	return -1;
    }
    
    if (getRowCount(o) != 0)
    {
	fprintf(stderr, "%s", "row count 0");
	return -1;
    }

    if (getData(o) != 0)
    {
	fprintf(stderr, "%s", "unable to assign memory at getData");
	return -1;
    }

    return 0;
}
