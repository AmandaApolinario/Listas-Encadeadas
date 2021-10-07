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

#endif