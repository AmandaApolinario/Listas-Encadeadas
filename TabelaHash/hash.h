#ifndef HASH_H
#define HASH_H

#include "palavra.h"

typedef struct hash Hash;

Hash* inicHash(int tam);

//insere a palavra ou incrementa se ela ja estiver la
Palavra* acessa(Hash* h, char* string);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);

#endif