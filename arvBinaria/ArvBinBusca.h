#ifndef ARVBINBUSCA_H
#define ARVBINBUSCA_H

#include "aluno.h"

typedef struct arv Arv;

Arv* arvBinCria(Arv* arv);

void arvBinImprime(Arv* arv);

Arv* arvBinBusca(Arv* arv, int mat);

Arv* arvBinInsere(Arv* arv, Aluno* al);

Arv* arvBinRetira(Arv* arv,int mat);

Arv* arvBinLibera(Arv* arv);

Aluno* retornaAluno(Arv* arv);

//retorna 1 se a arvore estiver vazia e 0 no contrario
int arvVazia(Arv *arvore);

//retorna 1 se o nome estiver na arvore e 0 caso contrario
int arvPertence(Arv *arvore, char* nome);

void arvImprime(Arv* arvore);

int qtdFolhasArv(Arv* arvore);

int qtdOcorrenciasArv(Arv* arvore,char *nome);

int alturaArv(Arv* arvore);

static int max(int a,int b);

#endif