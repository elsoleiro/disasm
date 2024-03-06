#ifndef FILE_OBJECT
#define FILE_OBJECT

typedef struct {
    const char *fileName;
    FILE *fptr;
    int fileSize;
    int rowCount;
    char *data;
} FileObject;

#endif
