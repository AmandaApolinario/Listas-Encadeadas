#ifndef TADPILHASDUPLAS_H
#define TADPILHASDUPLAS_H

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct tipopilhadupla TipoPilhaDupla;

TipoPilhaDupla* InicPilha();

void pushP1(TipoPilhaDupla *p, Aluno *aluno);

void pushP2(TipoPilhaDupla *p, Aluno *aluno);

Aluno* popP1(TipoPilhaDupla *p);

Aluno* popP2(TipoPilhaDupla *p);

void ImprimeP1(TipoPilhaDupla *p);

void ImprimeP2(TipoPilhaDupla *p);

void destroi(TipoPilhaDupla *p);


#endif