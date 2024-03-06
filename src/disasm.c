#include <stdio.h>
#include <stdlib.h>
#include "files/files.h"

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
    
    if (o.fptr == NULL)
    {
	fprintf(stderr, "%s", "possible incorrect filename");
	return -1;
    }

    if (getFileSize(&o) != 0)
    {
	fprintf(stderr, "%s", "file size 0");
	return -1;
    }
    
    if (getRowCount(&o) != 0)
    {
	fprintf(stderr, "%s", "row count 0");
	return -1;
    }

    printf("%d\n", o.rowCount);
    printf("%d", o.fileSize);
}
