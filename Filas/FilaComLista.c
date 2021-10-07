#include "Fila.h"

struct fila{
    Lista* lista;
};

Fila* inicFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->lista = InicLista();

    return fila;
}

//insere no final
void insereFila(Fila* fila, Filmes* filme){
    InsereLista(fila->lista,filme);
}

//retira do inicio
Filmes* retiraFila(Fila* fila){
    return RetiraLista(fila->lista);
}

void imprimeFila(Fila* fila){
    ImprimeLista(fila->lista);
}

void destroiFila(Fila* fila){
    DestroiLista(fila->lista);
    free(fila);
}