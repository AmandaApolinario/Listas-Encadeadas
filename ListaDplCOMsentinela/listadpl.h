#ifndef LISTADPL_H
#define LISTADPL_H

#include "filmes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* InicLista(void);

void InsereListaInicio(Lista *lista,Filmes* filme);

void InsereListaFinal(Lista *lista,Filmes* filme);

void RetiraListaInicio(Lista *lista);

void RetiraListaFim(Lista* lista);

void RetiraListaGenerico(Lista *lista,int codFilme);

void ImprimeLista(Lista *lista);

//para testar os anteriores se funciona
void ImprimeListaContrario(Lista *lista);

void DestroiLista(Lista *lista);

#endif