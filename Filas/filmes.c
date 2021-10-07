#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

struct filmes{
    char *nome;
    int nota;
};

Filmes* InicFilmes(char *nome,int nota){
    Filmes *filme = (Filmes*)malloc(sizeof(Filmes));
    filme->nome = strdup(nome);
    filme->nota = nota;

    return filme;
}

void ImprimeNomeFilme(Filmes *filme){
    printf("filme:%s ",filme->nome);
}

void ImprimeNota(Filmes *filme){
    printf("nota:%d\n",filme->nota);
}

void DestroiFilme(Filmes *filme){
    free(filme->nome);
    free(filme);
}