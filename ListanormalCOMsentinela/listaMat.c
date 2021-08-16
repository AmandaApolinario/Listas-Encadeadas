#include "listaMat.h"

typedef struct celula Celula;

struct celula{
    Matriz *mat;
    Celula *prox;
};

struct lista{
    Celula* prim;
    Celula *ult;
};

Lista* InicLista(){
    Lista *list = (Lista*)malloc(sizeof(Lista));
    list->prim = NULL;
    list->ult = NULL;

    return list;
}

void InsereLista(Lista* lista, Matriz* mat){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->mat = mat;
    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void ImprimeLista(Lista* lista){
    Celula *temp;
    for(temp = lista->prim;temp != NULL;temp = temp->prox){
        imprimeMatriz(temp->mat);
        printf("\n");
    }
}

void RetiraLista(Lista* lista, int posicao){
    Celula *temp = lista->prim;
    Matriz* mat;
    Celula *anterior = NULL;

    for(int i=0;i<posicao;i++){
        anterior = temp;
        temp = temp->prox; 
    }

    mat = temp->mat;

    if(temp == lista->prim && temp == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    else if(temp == lista->prim){
        lista->prim = temp->prox;
    }
    else if(temp == lista->ult){
        lista->ult = anterior;
        lista->ult->prox = NULL;
    }
    else{
        anterior->prox = temp->prox;
    }

    free(temp);

}

void DestroiLista(Lista* lista){
    Celula *temp = lista->prim;
    Celula *prox;

    while(temp != NULL){
        prox = temp->prox;
        destroiMatriz(temp->mat);
        free(temp);
        temp = prox;
    }

    free(lista);
}