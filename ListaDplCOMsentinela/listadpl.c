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

void InsereListaInicio(Lista *lista,Filmes* filme){
    //insere no inicio da lista
    Celula *nova = (Celula*)malloc(sizeof(Celula));


    nova->filme = filme;
    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void InsereListaFinal(Lista *lista,Filmes* filme){
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

void InsereListaGenerico(Lista *lista,Filmes* filme,int pos){

    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->filme = filme;

    if(pos == -1){
        nova->prox = lista->prim;

        lista->prim = nova;

        if(lista->ult == NULL){
            lista->ult = nova;
        }
        return;
    }

    Celula *temp=lista->prim;

    for(int i=0;i<pos;i++){
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("pos invalida\n");
        return;
        
    }
 
    nova->prox = temp->prox;
    temp->prox = nova;
    nova->ant = temp;
    if (nova->prox != NULL){
        nova->prox->ant = nova;
    }

    if(lista->ult == NULL){
        lista->ult = nova;
    }
    
}

void RetiraListaInicio(Lista *lista){
    Celula *retirar;
    retirar = lista->prim;

    lista->prim = retirar->prox;
    if(lista->prim == NULL){
        free(retirar);
        return;
    }
    lista->prim->ant = NULL;

    free(retirar);
}

void RetiraListaFinal(Lista* lista){
    /*Celula *retirar;
    retirar = lista->ult;

    if (retirar == lista->prim){ 
        lista->prim = retirar->prox;
    }
    else{
        retirar->ant->prox = retirar->prox;
    }
    if (retirar->prox != NULL){
        retirar->prox->ant = retirar->ant;
    }

    //free(retirar);*/
    
}
	
void RetiraListaGenerico(Lista *lista,int pos){
    Celula *retirar;
    retirar = lista->prim;

    for(int i=0;i<pos;i++){
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