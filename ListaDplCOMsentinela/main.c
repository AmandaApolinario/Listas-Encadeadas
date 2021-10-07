#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main(){
	Filmes *filme1 = InicFilmes("Atonement",1);
    Filmes *filme2 = InicFilmes("Before Sunset",5);
    Filmes *filme3 = InicFilmes("Clue",15);
    Filmes *filme4 = InicFilmes("Columbus",9);

    Lista *lista1 = InicLista();

	InsereListaGenerico(lista1,filme2,-1);
	InsereListaGenerico(lista1,filme3,-1);
	InsereListaInicio(lista1,filme1);

	ImprimeLista(lista1);
	//DestroiLista(lista1);

	return 0;
}