#ifndef LISTADPL_H
#define LISTADPL_H

#include "filmes.h"

typedef struct listadpl ListaDpl;

ListaDpl* InicLista(void);

ListaDpl* InsereLista(ListaDpl *lista,Filmes* filme);

ListaDpl* RetiraLista(ListaDpl *lista,int codFilme);

void ImprimeLista(ListaDpl *lista);

void DestroiLista(ListaDpl *lista);

#endif