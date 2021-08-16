#include <stdio.h>
#include <stdlib.h>
#include "ListaDpl.h"



struct listadpl{
    Filmes *filme;
    ListaDpl *ant;
    ListaDpl *prox;
};

ListaDpl* InicLista(void){
    return NULL;
}

ListaDpl* InsereLista(ListaDpl *lista,Filmes* filme){
    ListaDpl *nova = (ListaDpl*)malloc(sizeof(ListaDpl));

    nova->filme = filme;
    nova->ant = NULL;
    nova->prox = lista;

    if(lista != NULL){
        lista->ant = nova;
    }

    return nova;
}


ListaDpl* RetiraLista(ListaDpl *lista,int codFilme){
    ListaDpl *retirar;
    retirar = lista;

    while(RetornaCodigo(retirar->filme) != codFilme){
        retirar = retirar->prox;
    }
    
    if(retirar == NULL){
        return lista;
    }


    if (retirar == lista){ 
        lista = retirar->prox;
    }
    else{
        retirar->ant->prox = retirar->prox;
    }
    if (retirar->prox != NULL){
        retirar->prox->ant = retirar->ant;
    }

    free(retirar);

    return lista;

}

void ImprimeLista(ListaDpl *lista){
    ListaDpl *temp;
    temp = lista;

    while(temp!= NULL){
        ImprimeNome(temp->filme);
        temp = temp->prox;
    }
}

void ImprimeListaContrario(ListaDpl *lista){
    ListaDpl *temp,*temp2;
    temp = lista;
    temp2 = lista;

    while(1){
        temp2 = temp2->prox;
        if(temp2 != NULL){
            temp = temp->prox;
        }
        else{
            break;
        }
    }

    while(temp!= NULL){
        ImprimeNome(temp->filme);
        temp = temp->ant;
    }
}

void DestroiLista(ListaDpl *lista){
    ListaDpl *temp;
    temp = lista;

    while(temp != NULL){
        lista = temp;
        temp = temp->prox;

        DestroiFilme(lista->filme);
        free(lista);
        
    }
}