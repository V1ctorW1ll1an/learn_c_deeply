#ifndef FILES_H
#define FILES_H

// How to use
// *fileName: char indicating the file name
// *mode: mode the file will open
// (*callback): reference to the function that will be called if
//              the file is successfully opened
//*kwArgs: array of auxiliary variable references
void openFile(char mode[], char fileName[], void (*callback)(void *args[]), void *kwArgs[]);

#endif