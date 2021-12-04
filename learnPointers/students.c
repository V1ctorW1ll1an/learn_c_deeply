#include <stdio.h>
#include <stdlib.h>

#include "libs/consts.h"
#include "libs/structs.h"

void showStudents() {
    printf("Show from pointer function");
}

void searchStudent(char studentName[]) {
    struct Aluno *aluno = malloc(sizeof(struct Aluno));
    int i = 0;
    int studentExists = 0;

    // abrir arquivo
    FILE *file = fopen("alunos", "rb");

    if (file != NULL) {
        for (i = 0; i < TAM; i++) {
            fread(aluno, sizeof(struct Aluno), 1, file);
            if (strcmp(studentName, aluno->nome) == 0) {
                studentExists = 1;
                break;
            }
        }
    } else {
        printf("Erro ao ler o arquivo");
        exit(1);
    }

    // fechar o arquivo
    fclose(file);

    if (studentExists) {
        printf("\n\nDados do aluno: \n\n");
        printf("Nome: %s\n", aluno->nome);
        printf("Sigla: %s\n", aluno->turma.sigla);
        printf("Ano de Início: %d\n", aluno->turma.anoInicio);
        printf("Nome do curso: %s\n", aluno->turma.curso.nome);
    } else {
        printf("O aluno buscado não existe!\n");
    }

    free(aluno);
}

void readStudent(struct Aluno **aluno) {
    struct Aluno *typeAluno = *aluno;
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
