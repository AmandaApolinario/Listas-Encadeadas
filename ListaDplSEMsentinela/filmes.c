#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

struct filmes{
    char *nome;
    int codigoFilme;
};

Filmes* InicFilmes(char *nome,int codigo){
    Filmes *filme = (Filmes*)malloc(sizeof(Filmes));
    filme->nome = strdup(nome);
    filme->codigoFilme = codigo;

    return filme;
}

void ImprimeNome(Filmes *filme){
    printf("%s\n",filme->nome);
}

int RetornaCodigo(Filmes *filme){
    return filme->codigoFilme;
}

void DestroiFilme(Filmes *filme){
    free(filme->nome);
    free(filme);
}