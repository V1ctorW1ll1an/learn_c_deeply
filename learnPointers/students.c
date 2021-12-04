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