#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

int main(){
	  Filmes *filme1 = InicFilmes("Atonement",1);
    Filmes *filme2 = InicFilmes("Before Sunset",5);
    Filmes *filme3 = InicFilmes("Clue",15);
    Filmes *filme4 = InicFilmes("Columbus",9);

    Lista *lista = InicLista();
		ImprimeLista(lista);

    InsereLista(lista,filme4);
    InsereLista(lista,filme3);
    InsereLista(lista, filme2);
    InsereLista(lista,filme1);

		RetiraLista(lista, 1);
		RetiraLista(lista, 15);
		RetiraLista(lista,5);
		RetiraLista(lista, 9);
		ImprimeLista(lista);

		InsereLista(lista,filme4);
    InsereLista(lista,filme3);
    InsereLista(lista, filme2);
    InsereLista(lista,filme1);

		printf("\n\n");
		ImprimeLista(lista);

		DestroiLista(lista);
	return 0;
}