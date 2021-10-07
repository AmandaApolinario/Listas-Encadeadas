#include "palavra.h"

struct palavra{
    char* string;
    int ocorr;
    Palavra* prox;
};

Palavra* inicPalavra(char* str){
    Palavra* p = (Palavra*)malloc(sizeof(Palavra));

    p->string = strdup(str);
    p->ocorr = 0;
    p->prox = NULL;
    return p;
}

char* retornaString(Palavra* p){
    return p->string;
}

void atualizaOcorrencias(Palavra* p){
    p->ocorr++;
}

int retornaOcorrencias(Palavra* p){
    return p->ocorr;
}

Palavra* buscaPalavra(Palavra* p,char* nome){
    Palavra* temp;

    for(temp = p;temp != NULL;temp = temp->prox){
        if(strcmp(nome,temp->string) == 0){
            return temp;
        }
    }
    return NULL;
}

Palavra* inserePalavraLista(Palavra* lista,Palavra* p){
    p->prox = lista;
    return p;
}

int contaPalavraLista(Palavra* p){
    Palavra* pal;
    int i=0;

    for(pal = p;pal!=NULL;pal = pal->prox){
        i++;
    }
    return i;
}

void imprimeLista(Palavra* p){
    Palavra* temp;

    for(temp = p;temp != NULL; temp = temp->prox){
        printf("String: %s Ocorrencia: %d\n",temp->string,temp->ocorr);
    }
}

void liberaListaPalavra(Palavra* p){
    Palavra* temp = p;
    Palavra* t;

    while(temp != NULL){
        t = temp->prox;
        free(temp->string);
        free(temp);
        temp = t;
    }
}