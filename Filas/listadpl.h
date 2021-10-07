#ifndef LISTADPL_H
#define LISTADPL_H

#include "filmes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* InicLista(void);

void InsereLista(Lista *lista,Filmes* filme);

Filmes* RetiraLista(Lista *lista);

void ImprimeLista(Lista *lista);

void DestroiLista(Lista *lista);

#endif