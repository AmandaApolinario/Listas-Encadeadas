#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main(){
	Filmes *filme1 = InicFilmes("Atonement",1);
    Filmes *filme2 = InicFilmes("Before Sunset",5);
    Filmes *filme3 = InicFilmes("Clue",15);
    Filmes *filme4 = InicFilmes("Columbus",9);

    Lista *lista1 = InicLista();

    InsereListaInicio(lista1,filme1);
	InsereListaInicio(lista1,filme2);
	InsereListaInicio(lista1,filme3);
	InsereListaInicio(lista1,filme4);

	RetiraListaInicio(lista1);
	RetiraListaInicio(lista1);
	RetiraListaInicio(lista1);
	RetiraListaInicio(lista1);
	
    InsereListaInicio(lista1,filme1);
	InsereListaInicio(lista1,filme2);
	InsereListaInicio(lista1,filme3);
	InsereListaInicio(lista1,filme4);

	ImprimeLista(lista1);
	DestroiLista(lista1);

	return 0;
}