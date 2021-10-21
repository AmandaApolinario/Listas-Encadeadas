#include "ArvBinBusca.h"

struct arv{
    Aluno* al;
    Arv* esq;
    Arv* dir;
};

Arv* arvBinCria(Arv* arv){
    return NULL;
}

void arvBinImprime(Arv* arv){
    if(arv != NULL){
        printf("<%s %d",RetornaNomeAluno(arv->al),RetornaMat(arv->al));
        arvBinImprime(arv->esq);
        arvBinImprime(arv->dir);
        
        printf(">");
    }
    else{
        printf("<>");
    }
}

Arv* arvBinBusca(Arv* arv, int mat){
    if(arv == NULL){
        return NULL;
    }
    else if(RetornaMat(arv->al)> mat){
        return arvBinBusca(arv->esq,mat);
    }
    else if(RetornaMat(arv->al) < mat){
        return arvBinBusca(arv->dir,mat);
    }
    else{
        return arv;
    }
}

Arv* arvBinInsere(Arv* arv, Aluno* al){
    if(arv == NULL){
        arv = (Arv*)malloc(sizeof(Arv));
        arv->al = al;
        arv->esq = arv->dir = NULL;
    }
    else if(RetornaMat(al)< RetornaMat(arv->al)){
        arv->esq = arvBinInsere(arv->esq,al);
    }
    else{
        arv->dir = arvBinInsere(arv->dir,al);
    }
    return arv;
}

Arv* arvBinRetira(Arv* arv,int mat){
    if(arv == NULL){
        return NULL;
    }
    else if(RetornaMat(arv->al) > mat){
        arv->esq = arvBinRetira(arv->esq,mat);
    }
    else if(RetornaMat(arv->al) < mat){
        arv->dir = arvBinRetira(arv->dir,mat);
    }
    else{
        //eh a mat
        //tem q verificar se eh folha, so tem um filho ou dois

        if(arv->esq == NULL && arv->dir == NULL){
            //no folha
            free(arv);
            arv = NULL;
        }
        else if(arv->esq == NULL){
            Arv* temp = arv;
            arv = arv->dir;
            free(temp);
        }
        else if(arv->dir == NULL){
            Arv* temp = arv;
            arv = arv->esq;
            free(temp);
        }
        else{
            //tem dois filhos
            //acha o antecessor do no, que seria o mais a direita da arvore da esquerda
            Arv* temp = arv->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }

            //troca o no que vai ser retirado com o antecessor dele
            Aluno* tempAl = arv->al;
            arv->al = temp->al;
            temp->al = tempAl;


            arv->esq = arvBinRetira(arv->esq, mat);
        }
    }
    return arv;
}

Arv* arvBinLibera(Arv* arv){
    if(arv != NULL){
        arvBinLibera(arv->esq);
        arvBinLibera(arv->dir);

        DestroiAluno(arv->al);
        free(arv);
    }

    return NULL;
}

Aluno* retornaAluno(Arv* arv){
    return arv->al;
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