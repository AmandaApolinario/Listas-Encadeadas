#include "Fila.h"

#define TamMax 10

struct fila{
    int ini;
    int qtd;
    Filmes* filme[TamMax];
};

Fila* inicFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->ini = 0;
    fila->qtd = 0;
    return fila;
}

//insere no final
void insereFila(Fila* fila, Filmes* filme){
    if(!fila || fila->qtd >= TamMax){
        printf("Fila invalida ou cheia\n\n");
        return;
    }

    //acha o final da fila circular
    int pos = (fila->ini + fila->qtd) % TamMax;

    //inserindo no final
    fila->filme[pos] = filme;
    fila->qtd++;
}

//retira do inicio
Filmes* retiraFila(Fila* fila){

    if(!fila || fila->qtd == 0){
        printf("Fila vazia ou invalida\n");
        return NULL;
    }

    Filmes* f = fila->filme[fila->ini];

    //incremento circular do indice do inicio
    fila->ini = (fila->ini+1)%TamMax;

    fila->qtd--;

    return f;
}

void imprimeFila(Fila* fila){
    int i, pos=0;

    if(!fila){
        printf("fila vazia ou invalida\n");
        return;
    }

    for(i=0;i<fila->qtd;i++){
        pos = (fila->ini + i)%TamMax;
        ImprimeNomeFilme(fila->filme[pos]);
        ImprimeNota(fila->filme[pos]);
    }
}

void destroiFila(Fila* fila){
    int pos=0;
    if(!fila){
        return;
    }

    for(int i=0;i<fila->qtd;i++){
        pos = (fila->ini + i)%TamMax;
        DestroiFilme(fila->filme[pos]);
    }
    free(fila);
}