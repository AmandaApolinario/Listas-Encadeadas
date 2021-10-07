#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

Palavra* inicPalavra(char* str);

char* retornaString(Palavra* p);

void atualizaOcorrencias(Palavra* p);

int retornaOcorrencias(Palavra* p);

Palavra* buscaPalavra(Palavra* p,char* nome);

Palavra* inserePalavraLista(Palavra* lista,Palavra* p);

void imprimeLista(Palavra* p);

void liberaListaPalavra(Palavra* p);

#endif