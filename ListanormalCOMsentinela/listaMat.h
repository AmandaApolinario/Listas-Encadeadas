#ifndef LISTAMAT_H
#define LISTAMAT_H

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct lista Lista;

Lista* InicLista();

void InsereLista(Lista* lista, Matriz* mat);

void ImprimeLista(Lista* lista);

void RetiraLista(Lista* lista, int posicao);

void DestroiLista(Lista* lista);

#endif