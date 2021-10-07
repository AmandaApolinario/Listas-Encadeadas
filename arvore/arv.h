#ifndef ARV_H
#define ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arv Arv;

Arv* criaArvVazia(void);

Arv* criaArv(Aluno* al,Arv* esq, Arv * dir);

Arv* arvLibera(Arv *arvore);

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