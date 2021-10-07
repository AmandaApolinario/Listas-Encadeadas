#include "listadpl.h"

typedef struct celula Celula;

struct celula{
    Filmes *filme;
    Celula *prox;
		Celula *ant;
};

struct lista{
    Celula *prim;
    Celula *ult;
};

Lista* InicLista(void){
	  Lista *list = (Lista*)malloc(sizeof(Lista));
    list->prim = NULL;
    list->ult = NULL;

    return list;
}

void InsereLista(Lista *lista,Filmes* filme){
    //insere no fim da lista
	Celula *nova = (Celula*)malloc(sizeof(Celula));

    nova->filme = filme;
    nova->ant = lista->ult;

	if(nova->ant != NULL){
		nova->ant->prox = nova;
	}
	nova->prox = NULL;

    lista->ult = nova;

    if(lista->prim == NULL){
      lista->prim = nova;
    }

}
	
Filmes* RetiraLista(Lista *lista){
    //tem que retirar o primeiro q entrou, o primeiro da lista
    Celula *retirar;
    Filmes *filme;
    retirar = lista->prim;

    if(!lista){
        printf("lista vazia ou invalida\n");
        return NULL;
    }
    if(retirar->prox == NULL){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    else{
    lista->prim = retirar->prox;
    lista->prim->ant = NULL;
    }

    free(retirar);

    return filme;
		
}

void ImprimeLista(Lista *lista){
	  Celula *temp;
    temp = lista->prim;

    while(temp!= NULL){
        ImprimeNomeFilme(temp->filme);
        ImprimeNota(temp->filme);
        temp = temp->prox;
    }
}

void DestroiLista(Lista *lista){    
		Celula *temp = lista->prim;
    Celula *prox;

    while(temp != NULL){
        prox = temp->prox;
        DestroiFilme(temp->filme);
        free(temp);
        temp = prox;
    }

    free(lista);
}