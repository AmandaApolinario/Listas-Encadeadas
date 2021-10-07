#include "Aluno.h"


struct aluno{
    int mat;
    char *nome;
    float CR;
};

Aluno* InicAluno(int mat, char *nome,float CR){
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    novo->nome = strdup(nome);
    novo->mat = mat;
    novo->CR = CR;

    return novo;
}

void ImprimeAluno(Aluno *al){
    printf("mat: %d, Nome: %s, CR: %.2f\n",al->mat,al->nome,al->CR);
}

int RetornaMat(Aluno *al){
    return al->mat;
}

char *RetornaNomeAluno(Aluno *al){
    return al->nome;
}

float RetornaCR(Aluno *al){
    return al->CR;
}

void DestroiAluno(Aluno *al){
    free(al->nome);
    free(al);
}