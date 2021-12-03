#include <stdio.h>
#include <stdlib.h>

void cleanOutput() {
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(char msg[]) {
#ifdef WIN32
    printf("\n\n%s\n\n", msg);
    system("pause");
#else
    printf("\n\n%s\n\n", msg);
    cleanBuffer();
    printf("Pressione enter para continuar!!");
    int c = getchar();
    cleanOutput();
#endif
}

void cleanBuffer() {
#ifdef WIN32
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
}