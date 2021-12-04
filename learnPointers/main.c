
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/consts.h"
#include "libs/files.h"
#include "libs/structs.h"
#include "libs/students.h"
#include "libs/utils.h"

void menu() {
    int opcao;
    struct Aluno *aluno = malloc(sizeof(struct Aluno));
    char *studentName;
    void (*readStudentVar)(struct Aluno *) = &readStudent;

    do {
        printf(PURPLE);
        printf("\n############################# Menu ##############################");
        printf("\n# \t\t\t\t\t\t\t\t#");
        printf("\n# \t\t\t\t\t\t\t\t#");
        printf("\n# \t\t 0 - Sair \t\t\t\t\t#");
        printf("\n# \t\t 1 - Cadastrar Aluno \t\t\t\t#");
        printf("\n# \t\t 2 - Pesquisar Aluno \t\t\t\t#");
        printf("\n# \t\t 3 - callback function \t\t\t#");
        printf("\n# \t\t\t\t\t\t\t\t#");
        printf("\n# \t\t\t\t\t\t\t\t#");
        printf("\n#################################################################");
        printf(DEFAULT);

        printf("\n\n Opção (número): ");

        if (scanf("%d", &opcao) == 0) {
            cleanOutput();
            printf(RED);
            pause("Insira somente os número que estão no menu (1, 2 ou 3)!");
            printf(DEFAULT);
            cleanBuffer();
            cleanOutput();
        } else {
            switch (opcao) {
                case 0:
                    free(aluno);
                    free(studentName);
                    cleanOutput();
                    printf(GREEN);
                    printf("\n\nPrograma encerrado com sucesso!\n\n");
                    printf(DEFAULT);
                    break;
                case 1:
                    cleanOutput();
                    (*readStudentVar)(&aluno);  // &x -> y
                    openFile("alunos", "ab", &insertStudent, aluno);
                    pause("");
                    cleanOutput();
                    break;
                case 2:
                    cleanOutput();
                    studentName = getStudentName();
                    searchStudent(studentName);
                    pause("");
                    cleanOutput();
                    break;
                case 3:
                    openFile("alunos", "w", &insertStudent, aluno);
                    pause("");
                    cleanOutput();
                    break;
                default:
                    cleanOutput();
                    printf(YELLOW);
                    pause("Opção inválida!");
                    printf(DEFAULT);
                    cleanBuffer();
                    break;
            }
        }
    } while (opcao != 3);
}

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    cleanOutput();
    menu();
    return 0;
}
