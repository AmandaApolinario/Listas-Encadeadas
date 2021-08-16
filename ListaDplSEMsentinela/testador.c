#include <stdio.h>
#include <stdlib.h>
#include "ListaDpl.h"

int main(){

    Filmes *filme1 = InicFilmes("Atonement",1);
    Filmes *filme2 = InicFilmes("Before Sunset",5);
    Filmes *filme3 = InicFilmes("Clue",15);
    Filmes *filme4 = InicFilmes("Columbus",9);

    ListaDpl *lista = InicLista();
    lista = InsereLista(lista,filme4);
    lista = InsereLista(lista,filme3);
    lista = InsereLista(lista, filme2);
    lista = InsereLista(lista,filme1);

    printf("Lista na ordem criada:\n");
    ImprimeLista(lista);
    printf("\nLista na ordem inversa para testar o acesso ao anterior:\n");
    ImprimeListaContrario(lista);
    printf("\n\n");

    printf("Retirando o primeiro filme:\n");
    lista = RetiraLista(lista,1);
    ImprimeLista(lista);
    printf("\nRetirando o caso comum:\n");
    lista = RetiraLista(lista,15);
    ImprimeLista(lista);
    printf("\nRetirando o ultimo filme da lista:\n");
    lista = RetiraLista(lista,9);
    ImprimeLista(lista);
    printf("\nRetirando o unico elemento da lista:\n");
    lista = RetiraLista(lista,5);
    ImprimeLista(lista);

    printf("\n\nAdicionando os filmes de volta:\n");

    lista = InsereLista(lista,filme1);
    lista = InsereLista(lista,filme2);
    lista = InsereLista(lista,filme3);
    lista = InsereLista(lista,filme4);
    ImprimeLista(lista);

    DestroiLista(lista);

    return 0;
}