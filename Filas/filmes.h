#ifndef FILMES_H
#define FILMES_H

typedef struct filmes Filmes;

Filmes* InicFilmes(char *nome,int nota);

void ImprimeNomeFilme(Filmes *filme);

void ImprimeNota(Filmes *filme);

void DestroiFilme(Filmes *filme);

#endif