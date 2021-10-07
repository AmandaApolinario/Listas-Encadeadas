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