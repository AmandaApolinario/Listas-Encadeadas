#include "TadPilhasDuplas.h"
#define MaxTam 10

//typedef Aluno* TipoItem;

typedef struct{
    int Topo;
    int Base;
}IndicePilha;

struct tipopilhadupla{
    Aluno *alunos[MaxTam];
    IndicePilha Pilha1;
    IndicePilha Pilha2;
};

TipoPilhaDupla* InicPilha(){
    TipoPilhaDupla *p = (TipoPilhaDupla*)malloc(sizeof(TipoPilhaDupla));

    //alunos nao estao inicializados ainda

    p->Pilha1.Base = 0;
    p->Pilha1.Topo = 0;
    p->Pilha2.Base = MaxTam-1; 
    p->Pilha2.Topo = MaxTam-1;

    return p; 
    
}

void pushP1(TipoPilhaDupla *p, Aluno *aluno){
    if(!p || p->Pilha1.Topo == p->Pilha2.Topo+1 || !aluno){
        printf("Pilha cheia ou aluno invalido!\n\n");
        return;
    }


    p->alunos[p->Pilha1.Topo] = aluno;
    p->Pilha1.Topo++;

}



void pushP2(TipoPilhaDupla *p, Aluno *aluno){
    if(!p || p->Pilha1.Topo == p->Pilha2.Topo+1 || !aluno){
        printf("Pilha cheia ou aluno invalido!\n\n");
        return;
    }

    p->alunos[p->Pilha2.Topo] = aluno;
    p->Pilha2.Topo--;
}

Aluno* popP1(TipoPilhaDupla *p){
    if(!p || p->Pilha1.Topo == 0){
        printf("Pilha vazia");
        return NULL;
    }

    Aluno *al = p->alunos[p->Pilha1.Topo];
    p->Pilha1.Topo--;

    return al;
}

Aluno* popP2(TipoPilhaDupla *p){
    if(!p || p->Pilha2.Topo == MaxTam-1){
        printf("Pilha vazia");
        return NULL;
    }

    Aluno *al = p->alunos[p->Pilha2.Topo];
    p->Pilha2.Topo++;

    return al;
}

void ImprimeP1(TipoPilhaDupla *p){
    int i;

    if(!p){
        return;
    }

    for(i=(p->Pilha1.Topo-1);i>=p->Pilha1.Base;i--){
        ImprimeAluno(p->alunos[i]);
    }
}

void ImprimeP2(TipoPilhaDupla *p){
    int i;

    if(!p){
        return;
    }
    
    for(i=(p->Pilha2.Topo+1);i<=p->Pilha2.Base;i++){
        ImprimeAluno(p->alunos[i]);
    }
}

void destroi(TipoPilhaDupla *p){
    if(!p){
        return;
    }

    free(p);
}