
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/consts.h"
#include "libs/files.h"
#include "libs/structs.h"
#include "libs/students.h"
#include "libs/utils.h"

void readStudent(struct Aluno **aluno) {
    struct Aluno *typeAluno = *aluno;
    cleanOutput();
    printf(PURPLE);
    printf("\n\n ########## BEM VINDO A TELA DE INSERÇÃO DE ALUNO ########## \n\n");

    printf("\nInsira os dados corretamente para fazer o cadastro de um novo aluno!\n");

    printf("\n\n Aluno \n\n");
    printf(DEFAULT);

    cleanBuffer();
    printf("nome do aluno (max. 40 caracteres): ");
    fgets(typeAluno->nome, 40, stdin);
    cleanBuffer();

    printf("sigla da turma (max. 5 caracteres): ");
    fgets((*aluno)->turma.sigla, 5, stdin);
    cleanBuffer();

    printf("ano de início: ");
    while (scanf("%d", &((*aluno)->turma.anoInicio)) == 0) {
        printf(YELLOW);
        printf("\nATENÇÃO: O valor inserido é inválido, por favor, preencha o formulário corretamente!\n\n");
        printf(DEFAULT);
        printf("ano de início: ");
        cleanBuffer();
    }
    cleanBuffer();

    printf("nome do curso (max. 40 caracteres): ");
    fgets((*aluno)->turma.curso.nome, 40, stdin);
    cleanBuffer();
}

void appendInFile(struct Aluno *aluno) {
    FILE *file = fopen("alunos", "ab");

    if (file != NULL) {
        fwrite(aluno, sizeof(struct Aluno), 1, file);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
}

void insertStudent(void *parameters[]) {
    FILE *file = parameters[0];
    struct Aluno *student = parameters[1];

    fwrite(student, sizeof(struct Aluno), 1, file);
}

char *getStudentName() {
    char *studentName = malloc(40);
    cleanBuffer();
    printf("nome do aluno para pesquisar (max. 40 caracteres): ");
    fgets(studentName, 40, stdin);
    cleanBuffer();

    return studentName;
}

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
                    (*readStudentVar)(&aluno);  // &x -> y
                    openFile("alunos", "w", &insertStudent, aluno);
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
