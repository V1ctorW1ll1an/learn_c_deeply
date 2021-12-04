#include <stdio.h>

void openFile(
    char *fileName[],
    char *mode[],
    void (*callback)(void *args[]),
    void *kwArgs) {
    //
    FILE *file = fopen(fileName, mode);
    void *parameters[2];

    if (file == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    parameters[0] = file;
    parameters[1] = kwArgs;

    callback(&parameters);
    fclose(file);
}