#ifndef FILMES_H
#define FILMES_H

typedef struct filmes Filmes;

Filmes* InicFilmes(char *nome,int codigo);

void ImprimeNome(Filmes *filme);

int RetornaCodigo(Filmes *filme);

void DestroiFilme(Filmes *filme);

#endif