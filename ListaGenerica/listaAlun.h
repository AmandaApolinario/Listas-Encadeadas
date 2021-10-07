#ifndef LISTAALUN_H
#define LISTAALUN_H

#include "listaGen.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaGen* retiraAlun(ListaGen* lista,int matricula);

int pertenceAluno(ListaGen* lista,int matricula);

void imprimeListaAlunos(ListaGen* lista);

float mediaTurma(ListaGen* lista);

#endif