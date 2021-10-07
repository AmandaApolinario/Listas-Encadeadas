#include "listaAlun.h"

struct cr{
    float CR;
    int qtd;
};

//funcoes de callback

static int comparacaoMat(void* aluno1,void* aluno2){
    Aluno* a1 = (Aluno*)aluno1;
    Aluno* a2 = (Aluno*)aluno2;

    if(RetornaMat(a1) == RetornaMat(a2)){
        return 0;
    }

    return 1;
}

static int imprime(void* aluno, void* dado){
    ImprimeAluno(aluno);
    return 1;
}

static int acumula( void* aluno, void* dado){
    struct cr* acumulado = (struct cr*)dado;

    acumulado->CR += RetornaCR(aluno);
    acumulado->qtd++;
    return 1;
}

//acaba as funcoes de callback

ListaGen* retiraAlun(ListaGen* lista,int matricula){
    return retiraLista(lista,comparacaoMat,&matricula);
}

int pertenceAluno(ListaGen* lista,int matricula){
    return percorreLista(lista,comparacaoMat,&matricula);
}

void imprimeListaAlunos(ListaGen* lista){
    percorreLista(lista,imprime,NULL);
}

float mediaTurma(ListaGen* lista){
    struct cr* acumulado = (struct cr*)malloc(sizeof(struct cr));
    acumulado->CR = 0;
    acumulado->qtd = 0;

    percorreLista(lista, acumula,acumulado);

    float media = acumulado->CR/acumulado->qtd;

    free(acumulado);

    return media;
}