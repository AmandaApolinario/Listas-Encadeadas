#include "aluno.h"
#include "TadPilhasDuplas.h"

int main(){
    TipoPilhaDupla *p;
    Aluno * temp;
    p = InicPilha();

    Aluno *amanda = InicAluno(101,"Amanda",8.7);
    Aluno *ana = InicAluno(512,"Ana",5.5);
    Aluno *paula = InicAluno(918,"Paula",9.3);
    Aluno *matheus = InicAluno(111,"Matheus",8.5);
    Aluno *lorenzo = InicAluno(415,"Lorenzo", 9.2);
    Aluno *pedro = InicAluno(111,"Pedro",4.9);

    pushP1(p,amanda);
    pushP1(p,ana);
    pushP1(p,paula);
    pushP1(p,amanda);
    pushP1(p,ana);
    pushP1(p,paula);
    pushP1(p,amanda);

    pushP2(p,matheus);
    pushP2(p,lorenzo);
    pushP2(p,pedro);

    printf("aluno que nao cabe na pilha:\n");
    //aluno para testar se a pilha para quando esta cheia
    pushP2(p,pedro);

    printf("\nPilha 1:\n");
    ImprimeP1(p);

    printf("\nPilha 2:\n");
    ImprimeP2(p);

    temp = popP1(p);
    temp = popP1(p);
    temp = popP1(p);
    temp = popP1(p);
    temp = popP1(p);
    temp = popP1(p);
    temp = popP1(p);

    printf("\nPilha 1 com todos os alunos removidos:\n");
    ImprimeP1(p);

    temp = popP2(p);
    temp = popP2(p);
    temp = popP2(p);

    printf("\nPilha 2 com todos os alunos removidos:\n");
    ImprimeP2(p);

    pushP1(p,paula);
    pushP1(p,ana);
    pushP1(p,amanda);

    printf("\nPilha 1 adicionando os alunos novamente:\n");
    ImprimeP1(p);

    pushP2(p,pedro);
    pushP2(p,lorenzo);
    pushP2(p,matheus);

    printf("\nPilha 1 adicionando os alunos novamente:\n");
    ImprimeP2(p);

    destroi(p);
    DestroiAluno(amanda);
    DestroiAluno(ana);
    DestroiAluno(paula);
    DestroiAluno(matheus);
    DestroiAluno(lorenzo);
    DestroiAluno(pedro);

    return 0;
}