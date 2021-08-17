#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main(){
	Filmes *filme1 = InicFilmes("Atonement",1);
    Filmes *filme2 = InicFilmes("Before Sunset",5);
    Filmes *filme3 = InicFilmes("Clue",15);
    Filmes *filme4 = InicFilmes("Columbus",9);

    Lista *lista1 = InicLista();
	Lista *lista2 = InicLista();

    InsereListaInicio(lista1,filme1);
	InsereListaInicio(lista1,filme2);
	InsereListaInicio(lista1,filme3);
	InsereListaInicio(lista1,filme4);

	InsereListaFinal(lista2,filme1);
	InsereListaFinal(lista2,filme2);
	InsereListaFinal(lista2,filme3);
	InsereListaFinal(lista2,filme4);

	ImprimeLista(lista1);
	printf("\n\n");
	ImprimeLista(lista2);


	return 0;
}