#include "listaAlun.h"

int main(){

    Aluno* amanda = InicAluno(1,"Amanda",7);
    Aluno* ana = InicAluno(2,"Ana",8);
    Aluno* pedro = InicAluno(3,"Pedro",6);
    Aluno* leslye = InicAluno(4,"Leslye",7.5);
    Aluno* filipe = InicAluno(5,"Filipe",5);

    ListaGen* lista = criaLista();

    lista = insereLista(lista,amanda);
    lista = insereLista(lista,ana);
    lista = insereLista(lista,pedro);
    lista = insereLista(lista,leslye);
    lista = insereLista(lista,filipe);

    imprimeListaAlunos(lista);
    printf("\n");

    lista = retiraAlun(lista,3);
    imprimeListaAlunos(lista);
    printf("\n");

    int al=0;
    al  = pertenceAluno(lista,5);
    if(al == 0){
        printf("O aluno pertence a lista\n");
    }
    else{
        printf("O aluno nao pertence a lista\n");
    }

    float media = mediaTurma(lista);
    printf("a media da turma eh %.2f\n",media);


    liberaLista(lista);
    DestroiAluno(amanda);
    DestroiAluno(ana);
    DestroiAluno(pedro);
    DestroiAluno(leslye);
    DestroiAluno(filipe);

    return 0;
}