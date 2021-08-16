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
	Celula *nova = (Celula*)malloc(sizeof(Celula));

    nova->filme = filme;
    nova->ant = lista->ult;
		if(nova->ant != NULL){
			nova->ant->prox = nova;//e os casos especiais
		}
		nova->prox = NULL;

    lista->ult = nova;

    if(lista->prim == NULL){
      lista->prim = nova;
    }

}
	
void RetiraLista(Lista *lista,int codFilme){
    Celula *retirar;
    retirar = lista->prim;

		while(RetornaCodigo(retirar->filme) != codFilme){
				retirar = retirar->prox;
		}

    if (retirar == lista->prim){ 
        lista->prim = retirar->prox;
    }
    else{
        retirar->ant->prox = retirar->prox;
    }
    if (retirar->prox != NULL){
        retirar->prox->ant = retirar->ant;
    }

    free(retirar);
		
}

void ImprimeLista(Lista *lista){
	  Celula *temp;
    temp = lista->prim;

    while(temp!= NULL){
        ImprimeNome(temp->filme);
        temp = temp->prox;
    }
}

//para testar os anteriores se funciona
void ImprimeListaContrario(Lista *lista){
	Celula *temp;
	temp = lista->ult;

	while(temp != NULL){
		ImprimeNome(temp->filme);
		temp = temp->ant;
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