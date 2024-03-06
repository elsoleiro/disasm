#include <stdio.h>
#include <stdlib.h>
#include "files.h"

int main(void)
{
    FileObject o;
    o.fileName = "test.csv";
    o.fptr = fopen(o.fileName, "rb");
    
    if (getFileSize(&o) != 0)
	return -1;

    if (getRowCount(&o) != 0)
	return -1;

    printf("%d\n", o.rowCount);
    printf("%d\n", o.fileSize);
}
