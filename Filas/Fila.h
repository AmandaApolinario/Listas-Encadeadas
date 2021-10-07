#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"
//#include "listadpl.h"

typedef struct fila Fila;

Fila* inicFila();

//insere no final
void insereFila(Fila* fila, Filmes* filme);

//retira do inicio
Filmes* retiraFila(Fila* fila);

void imprimeFila(Fila* fila);

void destroiFila(Fila* fila);

#endif