#ifndef LISTAHET_H
#define LISTAHET_H

#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Professor.h"

typedef struct listahet ListaHet;

ListaHet* InicLista();

void InsereAluno(ListaHet* lista,Aluno* al);

void InsereProfessor(ListaHet* lista, Professor *prof);

void ImprimeListaHet(ListaHet* lista);

float ValorChurrasco(ListaHet* lista);

void DestroiLista(ListaHet* lista);

#endif