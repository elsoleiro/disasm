#include "fileobject.h"
#include "files.c"

#ifndef FILE_FUNCTIONS
#define FILE_FUNCTIONS

extern int getFileSize(FileObject *o);
extern int getRowCount(FileObject *o);

#endif