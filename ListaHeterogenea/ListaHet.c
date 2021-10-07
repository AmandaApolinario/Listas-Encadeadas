#include "ListaHet.h"

#define PROF 0
#define ALU 1

typedef struct celula Celula;

struct celula{
    Celula* prox;
    void* item;
    int tipo;
};

struct listahet{
    Celula* prim;
    Celula *ult;
};

ListaHet* InicLista(){
    ListaHet *list = (ListaHet*)malloc(sizeof(ListaHet));
    list->prim = NULL;
    list->ult = NULL;

    return list;
}

void InsereAluno(ListaHet* lista, Aluno *al){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->item = al;
    nova->tipo = ALU;
    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void InsereProfessor(ListaHet* lista, Professor *prof){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->item = prof;
    nova->tipo = PROF;
    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void ImprimeListaHet(ListaHet* lista){
    Celula *temp;

    for(temp = lista->prim;temp != NULL;temp = temp->prox){
        if(temp->tipo == ALU){
            printf("ALUNO: ");
            ImprimeAluno(temp->item);
        }

        else if(temp->tipo == PROF){
            printf("PROFESSOR: ");
            ImprimeProfessor(temp->item);
        }
    }
}

float ValorChurrasco(ListaHet* lista){
    Celula* temp = lista->prim;
    float valor = 0.0;

    while(temp != NULL){

        if(temp->tipo == PROF){
            valor = valor + 0.02*RetornaSalario(temp->item);
        }
        else if(temp->tipo == ALU){
            valor = valor + 30.0;
        }
        temp = temp->prox;
    }

    return valor;
}

void DestroiLista(ListaHet* lista){
    Celula *temp = lista->prim;
    Celula *prox;

    while(temp != NULL){
        prox = temp->prox;
        //acho q falta coisa
        free(temp);
        temp = prox;
    }

    free(lista);
}