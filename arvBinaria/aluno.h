#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* InicAluno(int mat, char *nome,float CR);

void ImprimeAluno(Aluno *al);

int RetornaMat(Aluno *al);

char *RetornaNomeAluno(Aluno *al);

float RetornaCR(Aluno *al);

void DestroiAluno(Aluno *al);

#endif