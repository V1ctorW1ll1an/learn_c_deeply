#ifndef STRUCTS_H
#define STRUCTS_H

struct Curso {
    char nome[40];
};

struct Turma {
    char sigla[5];
    int anoInicio;
    struct Curso curso;
};

struct Aluno {
    char nome[40];
    struct Turma turma;
};

#endif