#include "arv.h"

struct arv{
    Aluno* al;
    Arv* esq;
    Arv* dir;
};

Arv* criaArvVazia(void){
    return NULL;
}

Arv* criaArv(Aluno *al,Arv *esq, Arv *dir){
    Arv* p = (Arv*)malloc(sizeof(Arv));

    p->al = al;
    p->esq = esq;
    p->dir = dir;
}

Arv* arvLibera(Arv *arvore){
    if(arvVazia(arvore) == 0){
        arvLibera(arvore->esq);
        arvLibera(arvore->dir);

        free(arvore);
    }

    return NULL;
}

//retorna 1 se a arvore estiver vazia e 0 no contrario
int arvVazia(Arv *arvore){
    if(arvore == NULL){
        return 1;
    }
    return 0;
}

//retorna 1 se o nome estiver na arvore e 0 caso contrario
int arvPertence(Arv *arvore, char *nome){
    if(arvVazia(arvore) == 1){
        return 0;
    }
    else{
        return !strcmp(RetornaNomeAluno(arvore->al),nome) ||
        arvPertence(arvore->esq,nome) ||
        arvPertence(arvore->dir,nome);
    }
}

void arvImprime(Arv *arvore){
    if(arvVazia(arvore) == 0){
        printf(" <%s",RetornaNomeAluno(arvore->al));
        arvImprime(arvore->esq);
        arvImprime(arvore->dir);
        
        printf("> ");
    }
    else{
        printf(" <> ");
    }
}

int qtdFolhasArv(Arv *arvore){

    if(arvVazia(arvore->esq) == 1 && arvVazia(arvore->dir) == 1){
        //caso base
        return 1;
    }
    else if(arvVazia(arvore->esq) == 0 && arvVazia(arvore->dir)==1){
        return qtdFolhasArv(arvore->esq);
    }
    else if(arvVazia(arvore->esq) == 1 && arvVazia(arvore->dir)==0){
        return qtdFolhasArv(arvore->dir);
    }
    return qtdFolhasArv(arvore->esq) + qtdFolhasArv(arvore->dir);
    
}

int qtdOcorrenciasArv(Arv *arvore,char *nome){
    if(arvVazia(arvore) == 1){
        return 0;
    }

    if(strcmp(RetornaNomeAluno(arvore->al),nome)== 0){
        return (1 + qtdOcorrenciasArv(arvore->esq,nome) + qtdOcorrenciasArv(arvore->dir,nome));
    }
    else{
        return (qtdOcorrenciasArv(arvore->esq,nome) + qtdOcorrenciasArv(arvore->dir,nome));
    }
}

int alturaArv(Arv *arvore){
    if(arvVazia(arvore) == 1){
        return -1;
    }
    else{
        return 1 + max(alturaArv(arvore->esq),alturaArv(arvore->dir));
    }
}

static int max(int a,int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}